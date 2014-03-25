/*
 ============================================================================
 Name        : TravelingSalesmanProblem.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

#define IN 999

int a[10][10],visited[10],n,cost=0;
void mincost(int city) {
	int i,ncity;
	visited[city]=1;

	printf("%d -->",city+1);
	ncity = least(city);

	if(ncity == IN){
		ncity = 0;
		printf("%d", ncity+1);
		cost += a[city][ncity];
		return;
	}

	mincost(ncity);
}


int least(int c) {
	int i,nc=IN;
	int min=IN, kmin;

	for(i = 0; i < n; i++) {
		if((a[c][i] != 0) && (visited[i]==0))
			if(a[c][i] < min) {
				min = a[i][0] + a[c][i];
				kmin = a[c][i];
				nc = i;
			}
	}

	if(min != IN)
		cost += kmin;

	return nc;
}

void put() {
	printf("\n\nMinimum cost:");
	printf("%d",cost);
}


void main() {
	int i,j;
	clrscr();

	printf("Enter No. of Cities: ");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix: \n");

	for(i = 0; i < n; i++) {
		printf("\n Enter Elements of Row # : %d\n",i+1);

		for( j=0;j<n;j++)
			scanf("%d",&a[i][j]);

		visited[i]=0;
	}

	printf("\n\nThe cost list is:\n\n");

	for( i=0;i<n;i++) {
		printf("\n");

		for( j=0;j<n;j++)
			printf("\t%d",a[i][j]);
	}

	printf("\n\nThe Path is:\n");
	mincost(0);
	put();

	getch();
}

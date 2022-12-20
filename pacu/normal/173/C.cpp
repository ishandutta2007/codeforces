#include <cstdio>
#include <iostream>
using namespace std;

int A[501][501];
int psum[501][501];
int *spiral[501][501];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&A[i+1][j+1]);
	for(int i=0;i<=N;i++)
		psum[i][0] = 0;
	for(int j=0;j<=M;j++)
		psum[0][j] = 0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			psum[i][j] = A[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			spiral[i][j] = new int[min(N+2-i,M+2-j)/2];
			spiral[i][j][0] = A[i][j];
		}
	int best = -1000000000;
	for(int k=1;k<=250;k++)
		for(int i=1;(i+2*k)<=N;i++)
			for(int j=1;(j+2*k)<=M;j++)
			{
				spiral[i][j][k] = (psum[i+2*k][j+2*k]-psum[i-1][j+2*k]-psum[i+2*k][j-1]+psum[i-1][j-1])-spiral[i+1][j+1][k-1]-A[i+1][j];
				best = max(best,spiral[i][j][k]);
			}

	printf("%d\n",best);
	return 0;
}
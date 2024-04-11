#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int A[2000],B[2000];
int loc[2000];
int p[2000];
int N;
bool vis[2000];
long long cost;
int mv[2000000][2];
int M;

int pos[2000];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		loc[A[i]] = i;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&B[i]);
		B[i]--;
		loc[B[i]] = i;
	}
	for(int i=0;i<N;i++)
	{
		p[i] = loc[A[i]];
		pos[p[i]] = i;
//		printf("%d ",p[i]);
	}
//	printf("\n");
	M = 0;
	cost = 0;
	for(int i=N-1;i>=0;i--)
	{
		int k = pos[i]+1;
		while(pos[i] != i)
		{
//			cout << pos[i] << '\n';
			while(p[k] > pos[i])
				k++;
			cost += k-pos[i];
			mv[M][0] = pos[i];
			mv[M][1] = k;
			M++;
			swap(pos[i],pos[p[k]]);
			swap(p[pos[p[k]]],p[k]);
			k++;
		}
//		for(int i=0;i<N;i++)
//			printf("%d ",p[i]);
//		printf("\n");
	}
	printf("%I64d\n%d\n",cost,M);
	for(int i=0;i<M;i++)
		printf("%d %d\n",mv[i][0]+1,mv[i][1]+1);
}
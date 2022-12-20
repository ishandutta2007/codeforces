#include <cstdio>
#include <iostream>
using namespace std;
#define INF (1<<29)

int id[100000];
int sz[100000];

void init(int N)
{
	for(int i=0;i<N;i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
}

int find(int i)
{
	int j = i;
	while(id[j] != j)
		j = id[j];
	id[i] = j;
	return j;
}

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri==rj)
		return;
	if(sz[ri] < sz[rj])
	{
		id[ri] = rj;
		sz[rj] += sz[ri];
	}
	else
	{
		id[rj] = ri;
		sz[ri] += sz[rj];
	}
}

int u[100000];
int v[100000];
int x[100000];
int C[500];
int first[501];
int typ[100000];

int D[500][500];

int main()
{
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	init(N);
	for(int i=0;i<K;i++)
		scanf("%d",&C[i]);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&x[i]);
		u[i]--,v[i]--;
		if(x[i]==0)
			join(u[i],v[i]);
	}
	first[0] = 0;
	for(int i=1;i<K;i++)
		first[i] = first[i-1] + C[i-1];
	first[K] = N;
	for(int k=0;k<K;k++)
	{
		int a = first[k];
		for(int b=a;b<first[k+1];b++)
		{
			typ[b] = k;
			if(find(b) != find(a))
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");

	for(int i=0;i<K;i++)
	{
		for(int j=0;j<K;j++)
			D[i][j] = INF;
		D[i][i] = 0;
	}

	for(int i=0;i<M;i++)
	{
		D[typ[u[i]]][typ[v[i]]] = min(D[typ[u[i]]][typ[v[i]]],x[i]);
		D[typ[v[i]]][typ[u[i]]] = min(D[typ[v[i]]][typ[u[i]]],x[i]);
	}
	
	for(int k=0;k<K;k++)
		for(int i=0;i<K;i++)
			for(int j=0;j<K;j++)
				if(D[i][j] > (D[i][k]+D[j][k]))
					D[i][j] = D[i][k]+D[j][k];
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<K;j++)
		{
			if(D[i][j]==INF)
				printf("-1 ");
			else
				printf("%d ",D[i][j]);
		}
		printf("\n");
	}
	return 0;
}
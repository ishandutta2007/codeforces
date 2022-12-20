#include <cstdio>
using namespace std;

int cid[500];
int sz[500];
int components;

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		cid[i] = i;
		sz[i] = 1;
	}
	components = n;
}

int find(int i)
{
	int j = cid[i];
	while(j != cid[j]) j = cid[j];
	cid[i] = j;
	return j;
}

void join(int i,int j)
{
	int ri = find(i);
	int rj = find(j);
	if(ri==rj) return;
	if(sz[ri] < sz[rj])
	{
		cid[ri] = rj;
		sz[rj] += sz[ri];
	}
	else
	{
		cid[rj] = ri;
		sz[ri] += sz[rj];
	}
	components--;
}

int prefix[10000][500];
int suffix[10000][500];
int X[10000];
int Y[10000];


int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&X[i],&Y[i]);
		X[i]--,Y[i]--;
	}
	init(N);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
			prefix[i][j] = cid[j];
		join(X[i],Y[i]);
	}
	init(N);
	for(int i=(M-1);i>=0;i--)
	{
		for(int j=0;j<N;j++)
			suffix[i][j] = cid[j];
		join(X[i],Y[i]);
	}
	int K,l,r;
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		init(N);
		scanf("%d %d",&l,&r);
		l--,r--;
		for(int j=0;j<N;j++)
		{
			join(j,prefix[l][j]);
			join(j,suffix[r][j]);
		}
		printf("%d\n",components);
	}
	return 0;
}
#include <cstdio>
#include <iostream>
using namespace std;
#define MX 250000

char A[501][501];
int N,K;

int fid[MX];
int lx[MX],ly[MX],rx[MX],ry[MX],sz[MX];

void init()
{
	for(int i=0;i<N*N;i++)
		fid[i] = i, lx[i] = rx[i] = i/N, ly[i] = ry[i] = i%N, sz[i] = 1;
}
int find(int i)
{
	if(fid[i]==i) return i;
	fid[i] = find(fid[i]);
	return fid[i];
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	if(i==j) return;
	if(sz[i] > sz[j]) swap(i,j);
	fid[i] = j;
	sz[j] += sz[i];
	lx[j] = min(lx[j],lx[i]);
	rx[j] = max(rx[j],rx[i]);
	ly[j] = min(ly[j],ly[i]);
	ry[j] = max(ry[j],ry[i]);
}

int cntc[501][501];
int cntx[501][501];

int seen[250000];
int total;

void add(int x,int y,int idnum)
{
	if(x<0 || y<0 || x>=N || y>=N) return;
	if(A[x][y]=='X') return;
	int comp = find(N*x+y);
	if(seen[comp] != idnum+1)
	{
		seen[comp] = idnum+1;
		total += sz[comp];
	}
}

int main()
{
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++) scanf("%s",A[i]);
	init();
	for(int i=1;i<N;i++)
		for(int j=0;j<N;j++)
			if(A[i][j] == '.' && A[i-1][j] == '.') join(N*i+j,N*(i-1)+j);
	for(int i=0;i<N;i++)
		for(int j=1;j<N;j++)
			if(A[i][j] == '.' && A[i][j-1] == '.') join(N*i+j,N*i+j-1);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(A[i][j]=='.' && find(N*i+j)==N*i+j)
	{
		int lowx = rx[N*i+j];
		int highx = min(lx[N*i+j]+K-1,N-1);
		int lowy = ry[N*i+j];
		int highy = min(ly[N*i+j]+K-1,N-1);
		int csz = sz[N*i+j];
		if(lowx <= highx && lowy <= highy)
		{
			cntc[lowx][lowy]+=csz;
			cntc[lowx][highy+1]-=csz;
			cntc[highx+1][lowy]-=csz;
			cntc[highx+1][highy+1]+=csz;
		}
	}
	for(int i=0;i<N;i++) for(int j=0;j<N;j++)
	{
		if(i) cntc[i][j] += cntc[i-1][j];
		if(j) cntc[i][j] += cntc[i][j-1];
		if(i&&j) cntc[i][j] -= cntc[i-1][j-1];
		cntx[i][j] = (A[i][j]=='X');
		if(i) cntx[i][j] += cntx[i-1][j];
		if(j) cntx[i][j] += cntx[i][j-1];
		if(i&&j) cntx[i][j] -= cntx[i-1][j-1];
	}
	int best = 0;
	for(int i=K-1;i<N;i++) for(int j=K-1;j<N;j++)
	{
		total = 0;
		for(int k=0;k<K;k++)
		{
			add(i+1,j-k,N*i+j);
			add(i-k,j+1,N*i+j);
			add(i-K,j-k,N*i+j);
			add(i-k,j-K,N*i+j);
		}
		total += cntc[i][j];
		total += cntx[i][j];
		if(i>=K) total -= cntx[i-K][j];
		if(j>=K) total -= cntx[i][j-K];
		if(i>=K && j>=K) total += cntx[i-K][j-K];
		best = max(best,total);
	}
	printf("%d\n",best);
}
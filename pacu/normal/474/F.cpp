#include <iostream>
#include <cstdio>
using namespace std;
#define BSIZE 317
#define INF 1000000007

int gcd(int a,int b)
{
	if(a>b)
		return gcd(b,a);
	if(a==0)
		return b;
	if(a==1)
		return 1;
	return gcd(b%a,a);
}

int low[317];
int cLows[317];
int gcdiv[317];
int A[100000];
int N;

void calc(int block)
{
	low[block] = INF;
	cLows[block] = 0;
	gcdiv[block] = 0;
	for(int i = block*BSIZE; (i < (block+1)*BSIZE) && (i < N); i++)
	{
		if(A[i] == low[block])
			cLows[block]++;
		if(A[i] < low[block])
			cLows[block] = 1;
		low[block] = min(A[i],low[block]);

		gcdiv[block] = gcd(gcdiv[block],A[i]);
	}

}

int getLow(int l,int r,int &cntLow)
{
	int mn = INF;
	cntLow = 0;

	while((l%BSIZE)&&(l<=r))
	{
		if(A[l]==mn)
			cntLow++;
		else if(A[l]<mn)
			cntLow = 1;
		mn = min(mn,A[l]);
		l++;
	}
	while(((r+1)%BSIZE)&&(l<=r))
	{
		if(A[r]==mn)
			cntLow++;
		else if(A[r]<mn)
			cntLow = 1;
		mn = min(mn,A[r]);
		r--;
	}
	while(l != (r+1))
	{
		if(low[l/BSIZE]==mn)
			cntLow += cLows[l/BSIZE];
		else if(low[l/BSIZE]<mn)
			cntLow = cLows[l/BSIZE];
		mn = min(mn,low[l/BSIZE]);
		l += BSIZE;
	}
	return mn;
}

int getGCD(int l,int r)
{
	int g = 0;

	while((l%BSIZE)&&(l<=r))
	{
		g = gcd(g,A[l]);
		l++;
	}
	while(((r+1)%BSIZE)&&(l<=r))
	{
		g = gcd(g,A[r]);
		r--;
	}
	while(l != (r+1))
	{
		g = gcd(g,gcdiv[l/BSIZE]);
		l += BSIZE;
	}
	return g;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	int nBlocks = N/BSIZE;
	if((nBlocks*BSIZE)<N)
		nBlocks++;
	for(int i=0;i<nBlocks;i++)
		calc(i);
	int T,l,r;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d %d",&l,&r);
		int low,c;
		l--,r--;
		low = getLow(l,r,c);
		if(getGCD(l,r)%low)
			printf("%d\n",(1+r-l));
		else
			printf("%d\n",(1+r-l)-c);
	}
}
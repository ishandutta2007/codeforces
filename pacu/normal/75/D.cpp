#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define SEG (1<<18)

long long best[2*SEG],l[2*SEG],r[2*SEG],tot[2*SEG];

void fix(int i)
{
	best[i] = max(best[2*i],best[2*i+1]);
	best[i] = max(best[i],r[2*i]+l[2*i+1]);
	l[i] = max(l[2*i],tot[2*i]+l[2*i+1]);
	r[i] = max(r[2*i+1],tot[2*i+1]+r[2*i]);
	tot[i] = tot[2*i]+tot[2*i+1];
}

int A[250000];
int B[50][5000];
int sz[50];
int aB[50],aL[50],aR[50],aT[50];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<SEG;i++)
		best[i+SEG] = l[i+SEG] = r[i+SEG] = -1001;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&sz[i]);
		for(int j=0;j<sz[i];j++)
			scanf("%d",&B[i][j]);
		int b = -1001;
		int c = 0;
		for(int j=0;j<sz[i];j++)
		{
			c += B[i][j];
			b = max(b,c);
		}
		aL[i] = b;
		aT[i] = c;
		b = -1001, c = 0;
		for(int j=sz[i]-1;j>=0;j--)
		{
			c += B[i][j];
			b = max(b,c);
		}
		aR[i] = b;
		b = -1001,c = 0;
		for(int j=0;j<sz[i];j++)
		{
			b = max(b,B[i][j]);
			c += B[i][j];
			if(c < 0)
				c = 0;
			else
				b = max(b,c);
		}
		aB[i] = b;
	}
	for(int i=0;i<M;i++)
	{
		cin >> A[i];
		A[i]--;
	}
	for(int i=SEG;i<SEG+M;i++)
	{
		best[i] = aB[A[i-SEG]];
		l[i] = aL[A[i-SEG]];
		r[i] = aR[A[i-SEG]];
		tot[i] = aT[A[i-SEG]];
	}
	for(int i=SEG-1;i>0;i--)
		fix(i);
	printf("%I64d\n",best[1]);
	return 0;
}
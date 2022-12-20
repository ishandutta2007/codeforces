#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int x[1000000],y[1000000];
int cidx[1000000],cidy[1000000];

bool cmp(int a,int b)
{
	if(x[a]/700 == x[b]/700)
	{
		if((x[a]/700)%2) return y[a]>y[b];
		else return y[a]<y[b];
	}
	return x[a]/700 < x[b]/700;
}

int ggabs(int a)
{
	if(a<0) return -a;
	return a;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		cidx[i] = cidy[i] = i;
	}
	long long ansx = 0;
	sort(cidx,cidx+N,cmp);
	for(int i=0;i<N-1;i++)
	{
		ansx += ggabs(x[cidx[i]]-x[cidx[i+1]])+ggabs(y[cidx[i]]-y[cidx[i+1]]);
	}
	if(ansx <= 2500000000LL)
	{
		for(int i=0;i<N;i++)
			printf("%d ",cidx[i]+1);
	}
	else
	{
		while(1)
		{
			ansx = 0;
		}
	}
	printf("\n");
}
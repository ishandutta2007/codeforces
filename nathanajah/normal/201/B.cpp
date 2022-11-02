#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
    #define debug(...) \
    fprintf(stderr,__VA_ARGS__)
#else
    #define debug(...)
#endif
using namespace std;

long long n,m;
long long c[1005][1005];
long long sumr[1005];
long long sumd[1005];
long long i,j;
long long min1,min2,nummin1,nummin2;
long long now;
long long dist;
long long INF=1000000000000000000LL;

int main()
{
	min1=INF;
	min2=INF;
	scanf("%I64d %I64d",&n,&m);
	for (i=0;i<n;++i)
	{
		for (j=0;j<m;++j)
		{
			scanf("%I64d",&c[i][j]);
			sumr[i]+=c[i][j];
			sumd[j]+=c[i][j];
		}
	}
	for (i=0;i<=n;++i)
	{
		now=0;
		for (j=0;j<n;++j)
		{
			dist=abs(4*i-(4*j+2));
			now=now+sumr[j]*dist*dist;
		}
		if (now<min1)
		{
			min1=now;
			nummin1=i;
		}
	}
	for (i=0;i<=m;++i)
	{
		now=0;
		for (j=0;j<m;++j)
		{
			dist=abs(4*i-(4*j+2));
			now=now+sumd[j]*dist*dist;
		}
		if (now<min2)
		{
			min2=now;
			nummin2=i;
		}
	}
	printf("%I64d\n",min1+min2);
	printf("%I64d %I64d\n",nummin1,nummin2);
}
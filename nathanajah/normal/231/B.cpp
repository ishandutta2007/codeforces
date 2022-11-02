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

int n,d,l;
int i;
int now;
int hasil[2000];

int main()
{
	scanf("%d %d %d",&n,&d,&l);
	if (d>0)
	{
		now=(n+1)/2 - (n/2);
		for (i=0;i<n;++i)
			hasil[i]=1;
		for (i=0;i<n;i+=2)
		{
			hasil[i]+=min(l-1,d-now);
			now+=hasil[i]-1;
		}
		if (hasil[n-1]>l || now!=d)
			printf("-1\n");
		else
			for (i=0;i<n;++i)
				printf("%d ",hasil[i]);
	}
	else
	{
		now=(n+1)/2-(n/2);
		for (i=0;i<n;++i)
			hasil[i]=1;
		for (i=1;i<n;i+=2)
		{
			hasil[i]+=min(l-1,now-d);
			now-=hasil[i]-1;
		}
		int tmp=n-1;
		if (tmp%2==0)
			--tmp;
		if (hasil[tmp]>l || now!=d)
			printf("-1\n");
		else
			for (i=0;i<n;++i)
				printf("%d ",hasil[i]);
	}
}
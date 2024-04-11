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

int x,t,a,b,da,db,i,j;

int main()
{
	scanf("%d %d %d %d %d %d",&x,&t,&a,&b,&da,&db);
	for (i=0;i<t;++i)
		for (j=0;j<t;++j)
		{
			if ((a-da*i) + (b-db*j)==x)
			{
				printf("YES\n");
				return 0;
			}
		}
	for (i=0;i<t;++i)
		if (a-da*i==x)
		{
			printf("YES\n");
			return 0;
		}
	for (i=0;i<t;++i)
		if (b-db*i==x)
		{
			printf("YES\n");
			return 0;
		}
	if (x==0)
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
}
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

int sum[1005][1005];
int n,m,i,j,k;
int x,y;
bool bisa;
int main()
{
	scanf("%d %d",&n,&m);
	for (i=0;i<m;++i)
	{
		scanf("%d %d",&x,&y);
		for (j=x-2;j<=x;++j)
			for (k=y-2;k<=y;++k)
				if (j>=0 && k>=0)
				{
					++sum[j][k];
					if (sum[j][k]==9)
						bisa=true;
				}
		if (bisa)
			break;
	}
	if (bisa)
		printf("%d\n",i+1);
	else
		printf("-1\n");
}
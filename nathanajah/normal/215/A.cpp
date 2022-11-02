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

int n,m,i,j;
int a[100];
int b[100];
int maxi=-1;
int res=0;
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (i=0;i<m;++i)
		scanf("%d",&b[i]);
	for (i=0;i<n;++i)
		for (j=0;j<m;++j)
		{
			if (b[j]%a[i]==0)
			{
				maxi=max(maxi,b[j]/a[i]);
			}
		}
	for (i=0;i<n;++i)
		for (j=0;j<m;++j)
			if (b[j]%a[i]==0)
				if (b[j]/a[i]==maxi)
					++res;
	printf("%d\n",res);
}
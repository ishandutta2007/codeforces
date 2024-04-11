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

int n,i;
int x[200],y[200];
int cntx[2000],cnty[2000];
bool sudah[200];
int sz;

void jalan(int xx)
{	
	int i;
	for (i=0;i<n;++i)
		if (x[i]==x[xx] || y[i]==y[xx])
		{
			if (!sudah[i])
			{
				sudah[i]=true;
				jalan(i);
			}
		}
}
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d %d",&x[i],&y[i]);
		++cntx[x[i]];++cnty[y[i]];
	}
	for (i=0;i<n;++i)
	{
		if (!sudah[i])
		{
			sudah[i]=true;
			jalan(i);
			++sz;
		}
	}
	printf("%d\n",sz-1);
}
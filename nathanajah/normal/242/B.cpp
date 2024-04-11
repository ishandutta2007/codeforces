//nathanajah's template
//25-10-2012
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
#define LL long long
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,i;
int l[200000],r[200000];
int minl=1000000005,maxr=-1000000005;

int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d %d",&l[i],&r[i]);
		minl=min(minl,l[i]);
		maxr=max(maxr,r[i]);
	}
	for (i=0;i<n;++i)
		if (l[i]==minl && r[i]==maxr)
			break;
	if (i==n)
		printf("-1\n");
	else
		printf("%d\n",i+1);
}
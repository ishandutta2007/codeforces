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

int n,i,h,m;
int prevh,prevm;
int cnt;
int maxi;
int main()
{
	prevh=-1;
	cnt=0;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d %d",&h,&m);
		if (h==prevh && m==prevm)
			++cnt;
		else
		{
			maxi=max(maxi,cnt);
			cnt=1;
			prevh=h;
			prevm=m;
		}
	}
	maxi=max(maxi,cnt);
	printf("%d\n",maxi);
}
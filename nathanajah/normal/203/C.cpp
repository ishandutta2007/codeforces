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

long long n,d;
long long a,b;
long long i,j;
pair<long long,long long> total[200000];
long long x,y;
long long now;
int main()
{
	scanf("%I64d %I64dd",&n,&d);
	scanf("%I64d %I64d",&a,&b);
	for (i=0;i<n;++i)
	{
		scanf("%I64d %I64d",&x,&y);
		total[i].first=a*x+b*y;
		total[i].second=i;
	}
	sort(total,total+n);
	i=0;
	now=0;
	while (i<n && now+total[i].first<=d)
	{
		now+=total[i].first;
		++i;
	}
	printf("%I64d\n",i);
	for (j=0;j<i;++j)
		printf("%I64d ",total[j].second+1);
	printf("\n");
}
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

long long n,k;
long long arr[200000];
long long i,pnt;
long long raisnow;
long long maxi,nummax;

int main()
{
	scanf("%I64d %I64d",&n,&k);
	for (i=0;i<n;++i)
		scanf("%I64d",&arr[i]);
	sort(arr,arr+n);
	pnt=0;
	raisnow=0;
	for (i=0;i<n;++i)
	{
		while (raisnow>k)
		{
			raisnow-=arr[i]-arr[pnt];
			++pnt;
		}
		if (i-pnt+1>maxi)
		{
			maxi=i-pnt+1;
			nummax=arr[i];
		}
		raisnow+=(i-pnt+1)*(arr[i+1]-arr[i]);
	}
	printf("%I64d %I64d\n",maxi,nummax);
}
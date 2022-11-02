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

map <long long, long long> pre;
long long arr[100005];
long long k,b,n;
long long pres;
long long res;
long long nol;
long long tmp;
long long i,j;

int main()
{
	scanf("%I64d %I64d %I64d",&k,&b,&n);
	for (i=0;i<n;++i)
		scanf("%I64d",&arr[i]);
	for (i=0;i<n;++i)
	{
		if (arr[i]!=0)
		{
			nol+=(tmp*(tmp+1))/2;
			tmp=0;
		}
		else
			++tmp;
	}
	nol+=(tmp*(tmp+1))/2;
	pre[0]=1;
	for (i=0;i<n;++i)
	{
		pres=(pres+arr[i])%(k-1);
		res+=pre[(pres-b+(2*k-2))%(k-1)];
		++pre[pres];
	}
	if (b==0)
		printf("%I64d\n",nol);
	else if (b==k-1)
		printf("%I64d\n",res-nol);
	else
		printf("%I64d\n",res);
}
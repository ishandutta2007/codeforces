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

int a,b,k;
bool notprime[1000005];
int i,j;
int banyaknow;
int maxi;

int main()
{
	notprime[1]=true;
	notprime[0]=true;
	for (i=2;i<=1003;++i)
		if (!notprime[i])
			for (j=i*i;j<=1000003;j+=i)
				notprime[j]=true;
	scanf("%d %d %d",&a,&b,&k);
	i=a;
	j=a;
	banyaknow=0;
	if (!notprime[a])
		banyaknow=1;
	while (banyaknow<k)
	{
		++j;
		if (j>b)
		{
			printf("-1\n");
			return 0;
		}
		if (!notprime[j])
			++banyaknow;
	}
	maxi=j-i+1;
	++j;
	while (j<=b)
	{
		if (!notprime[j])
			++banyaknow;
		while (banyaknow>k)
		{
			if (!notprime[i])
				--banyaknow;
			++i;
		}
		while (notprime[i])
			++i;
		maxi=max(maxi,j-i+1);
		++j;
	}
	printf("%d\n",maxi);
}
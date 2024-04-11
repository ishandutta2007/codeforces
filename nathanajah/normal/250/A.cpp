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
#include <ctime>
#define LL long long
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFF
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,i;
int dp[500];
int arr[500];
int nummin[500];

int hitung(int x)
{
	int &ret=dp[x];
	if (ret>=0)
		return ret;
	if (x==0)
		return 0;
	else
	{
		ret=1000000000;
		int sum=0;
		int i;
		for (i=x-1;i>=0;--i)
		{
			if (arr[i+1]<0)
				++sum;
			if (sum<3)
			{
				if (hitung(i)+1<ret)
				{
					ret=hitung(i)+1;
					nummin[x]=i;
				}
			}
		}
		return ret;
	}
}
void backtrack(int x)
{
	if (x==0)
		return;
	backtrack(nummin[x]);
	printf("%d ",x-nummin[x]);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	if (hitung(n)==1000000000)
		printf("-1\n");
	else
	printf("%d\n",hitung(n));
	backtrack(n);
}
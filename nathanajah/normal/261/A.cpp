//nathanajah's template
//28-11-2012
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
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define LL long long
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

int n,i;
int m;

int mindisc;
int arr[100005];
int tmp;
int sum[100005];
int dp[100005];

int psum(int l, int r)
{
	if (l==0)
		return sum[r];
	return sum[r]-sum[l-1];
}
int hitung(int x)
{
	if (x==-1)
		return 0;
	int &ret=dp[x];
	if (ret>=0)
		return ret;
	ret=hitung(x-1)+arr[x];
	if (x-mindisc-2>=-1)
		ret=min(ret,psum(x-mindisc+1,x)+hitung(x-mindisc-2));
	if (x-mindisc-1>=-1)
		ret=min(ret,psum(x-mindisc+1,x)+hitung(x-mindisc-1));
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	mindisc=INF;
	scanf("%d",&m);
	for (i=0;i<m;++i)
	{
		scanf("%d",&tmp);
		mindisc=min(mindisc,tmp);
	}
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	sum[0]=arr[0];
	for (i=1;i<n;++i)
		sum[i]=sum[i-1]+arr[i];
	i=0;
	printf("%d\n",hitung(n-1));
}
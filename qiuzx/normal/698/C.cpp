#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 2000010
using namespace std;
ll n,k,cnt=0;
double p[N],dp[N],ans[N];
int main(){
	ll i,j;
	double sum;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
		if(p[i]!=0)
		{
			cnt++;
		}
	}
	dp[0]=1;
	for(i=0;i<(1<<n);i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			if(!(i&(1<<j)))
			{
				sum+=p[j];
			}
		}
		if(sum==0)
		{
			continue;
		}
		for(j=0;j<n;j++)
		{
			if(!(i&(1<<j)))
			{
				dp[i|(1<<j)]+=dp[i]*p[j]/sum;
			}
		}
	}
	for(i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)==min(k,cnt))
		{
			for(j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					ans[j]+=dp[i];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(p[i]==0)
		{
			cout<<0<<" ";
		}
		else
		{
			printf("%.15lf ",ans[i]);
		}
	}
	puts("");
	return 0;
}
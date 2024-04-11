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
#define N 100010
using namespace std;
ll n,d,a[N],lst[N][10];
bool chs[N][10];
double val[N],dp[N][10];
vector<ll> ans;
void get_path(ll x,ll y)
{
	if(chs[x][y])
	{
		ans.push_back(a[x-1]);
	}
	if(x==1)
	{
		return;
	}
	get_path(x-1,lst[x][y]);
	return;
}
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		val[i]=log(a[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<10;j++)
		{
			dp[i][j]=-100000000;
		}
	}
	dp[0][1]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			if(dp[i+1][j]<=dp[i][j])
			{
				dp[i+1][j]=dp[i][j];
				lst[i+1][j]=j;
				chs[i+1][j]=0;
			}
			if(dp[i+1][(j*a[i])%10]<=dp[i][j]+val[i])
			{
				dp[i+1][(j*a[i])%10]=dp[i][j]+val[i];
				lst[i+1][(j*a[i])%10]=j;
				chs[i+1][(j*a[i])%10]=1;
			}
		}
	}
	if(dp[n][d]<0)
	{
		puts("-1");
		return 0;
	}
	get_path(n,d);
	if(ans.size()==0)
	{
		puts("-1");
		return 0;
	}
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]);
	}
	puts("");
	return 0;
}
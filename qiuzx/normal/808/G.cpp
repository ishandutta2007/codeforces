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
char buf[N];
string s,t;
bool pos[N];
ll n,m,dp[N],ans=0;
int main(){
	ll i,j,pre;
	scanf("%s",&buf);
	s=buf;
	n=s.size();
	scanf("%s",&buf);
	t=buf;
	m=t.size();
	if(n<m)
	{
		puts("0");
		return 0;
	}
	memset(pos,false,sizeof(pos));
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(t[j]!=t[j-i-1])
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			pos[i]=true;
		}
	}
	memset(dp,-63,sizeof(dp));
	pre=0;
	for(i=m-1;i<n;i++)
	{
		for(j=i;j>i-m;j--)
		{
			if(s[j]!=t[j-i+m-1]&&s[j]!='?')
			{
				break;
			}
			if(pos[i-j])
			{
				dp[i]=max(dp[i],(j==0?0:dp[j-1])+1);
			}
			if(j==i-m+1)
			{
				dp[i]=max(dp[i],pre+1);
			}
		}
		pre=max(pre,dp[i-m+1]);
	}
	for(i=0;i<n;i++)
	{
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
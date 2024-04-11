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
#define N 200010
using namespace std;
string s;
char buf[N];
ll dp[N][2],ans,tot[N];
int main(){
	ll T,i,j,lst;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%s",&buf);
		s=buf;
		for(i=0;i<s.size();i++)
		{
			dp[i][0]=dp[i][1]=0;
		}
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				dp[i][0]=1;
			}
			else if(s[i]=='1')
			{
				dp[i][1]=1;
			}
			else
			{
				dp[i][0]=dp[i][1]=1;
			}
			if(i>0)
			{
				if(s[i]!='1')
				{
					dp[i][0]+=dp[i-1][1];
				}
				if(s[i]!='0')
				{
					dp[i][1]+=dp[i-1][0];
				}
			}
			if(s[i]=='?')
			{
				tot[i]=tot[i-1]+1;
			}
			else
			{
				tot[i]=dp[i][0]+dp[i][1];
			}
		}
		ans=0;
		for(i=0;i<s.size();i++)
		{
			ans+=tot[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
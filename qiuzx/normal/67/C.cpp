//ANMHLIJKTJIY!
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 4010
using namespace std;
ll ti,td,te,tr,nxt[N][26],nxt2[N][26],dp[N][N],n,m;
string s,t;
int main(){
	ll i,j,ni,nj;
	cin>>ti>>td>>tr>>te>>s>>t;
	n=s.size(),m=t.size();
	for(i=n;i>=0;i--)
	{
		s[i]=s[i-1];
	}
	s[0]=0;
	for(i=m;i>=0;i--)
	{
		t[i]=t[i-1];
	}
	t[0]=0;
	memset(nxt,-1,sizeof(nxt));
	memset(nxt2,-1,sizeof(nxt2));
	for(i=n;i>0;i--)
	{
		for(j=0;j<26;j++)
		{
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i]-'a']=i;
	}
	for(i=m;i>0;i--)
	{
		for(j=0;j<26;j++)
		{
			nxt2[i][j]=nxt2[i+1][j];
		}
		nxt2[i][t[i]-'a']=i;
	}
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i<n&&j<m)
			{
				if(s[i+1]==t[j+1])
				{
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
				}
			}
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+ti);
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+td);
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+tr);
			if(i<n&&j<m)
			{
				nj=nxt2[j+2][s[i+1]-'a'];
				ni=nxt[i+2][t[j+1]-'a'];
				if(ni!=-1&&nj!=-1)
				{
					dp[ni][nj]=min(dp[ni][nj],dp[i][j]+td*(ni-i-2)+te+ti*(nj-j-2));
				}
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
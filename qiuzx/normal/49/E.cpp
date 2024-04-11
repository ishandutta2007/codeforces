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
#define N 55 
using namespace std;
string s,t;
ll n,dp[N][N];
bool pos1[N][N][30],pos2[N][N][30];//can l~r be replaced by character c
pair<ll,pair<ll,ll> > rule[N];
ll dfs(ll la,ll lb)
{
	if(la<0&&lb<0)
	{
		return 0;
	}
	if(la<0||lb<0)
	{
		return LINF;
	}
	if(dp[la][lb]!=-1)
	{
		return dp[la][lb];
	}
	dp[la][lb]=LINF;
	ll i,j,k;
	for(i=0;i<26;i++)
	{
		for(j=0;j<=la;j++)
		{
			for(k=0;k<=lb;k++)
			{
				if(pos1[j][la][i]&&pos2[k][lb][i])
				{
					dp[la][lb]=min(dp[la][lb],dfs(j-1,k-1)+1);
				}
			}
		}
	}
	return dp[la][lb];
}
int main(){
	ll i,j,k,l,sz,ans;
	string ss;
	cin>>s>>t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ss;
		rule[i].F=(ss[0]-'a');
		rule[i].S.F=(ss[3]-'a');
		rule[i].S.S=(ss[4]-'a');
	}
	memset(dp,-1,sizeof(dp));
	memset(pos1,false,sizeof(pos1));
	memset(pos2,false,sizeof(pos2));
	for(i=0;i<s.size();i++)
	{
		pos1[i][i][s[i]-'a']=true;
	}
	for(i=0;i<t.size();i++)
	{
		pos2[i][i][t[i]-'a']=-true;
	}
	for(sz=1;sz<s.size();sz++)
	{
		for(i=0;i+sz<s.size();i++)
		{
			j=i+sz;
			for(k=i+1;k<=j;k++)
			{
				for(l=0;l<n;l++)
				{
					pos1[i][j][rule[l].F]|=(pos1[i][k-1][rule[l].S.F]&&pos1[k][j][rule[l].S.S]);
				}
			}
		}
	}
	for(sz=1;sz<t.size();sz++)
	{
		for(i=0;i+sz<t.size();i++)
		{
			j=i+sz;
			for(k=i+1;k<=j;k++)
			{
				for(l=0;l<n;l++)
				{
					pos2[i][j][rule[l].F]|=(pos2[i][k-1][rule[l].S.F]&&pos2[k][j][rule[l].S.S]);
				}
			}
		}
	}
	ans=dfs(s.size()-1,t.size()-1);
	if(ans<LINF)
	{
		cout<<ans<<endl;
	}
	else
	{
		puts("-1");
	}
	return 0;
}
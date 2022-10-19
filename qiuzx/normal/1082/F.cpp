#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
#define LINF 1000000000000000000
#define F first
#define S second
#define N 510
using namespace std;
ll n,m,app[N],sum=0,ans=0,val[N*15],dp[N][N][12];
bool vis[N][12];
string s[N];
vector<pair<ll,ll> > num;
vector<ll> vt[N*15];
ll dfs(ll x,ll lstdep,ll req,ll d)
{
	if(dp[x][lstdep][req]!=-1)
	{
		return dp[x][lstdep][req];
	}
	ll i,j,l,tmp[12],tr[12],nxt[12];
	memset(tmp,0,sizeof(tmp));
	memset(tr,0,sizeof(tr));
	for(i=0;i<vt[x].size();i++)
	{
		for(j=0;j<=req;j++)
		{
			tmp[j]=dfs(vt[x][i],lstdep,j,d+1);
		}
		memset(nxt,63,sizeof(nxt));
		for(j=0;j<=req;j++)
		{
			for(l=0;l<=j;l++)
			{
				nxt[j]=min(nxt[j],tmp[l]+tr[j-l]);
			}
		}
		for(j=0;j<=req;j++)
		{
			tr[j]=nxt[j];
		}
	}
	dp[x][lstdep][req]=tr[req]+val[x]*(d-lstdep);
	if(req>0&&d!=lstdep)
	{
		dp[x][lstdep][req]=min(dp[x][lstdep][req],dfs(x,d,req-1,d));
	}
	return dp[x][lstdep][req];
}
int main(){
	ll i,j,k,lst;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s[i]>>app[i];
	}
	num.push_back(make_pair(0,-1));
	for(i=0;i<n;i++)
	{
		bool hv=true;
		lst=0;
		for(j=0;j<s[i].size();j++)
		{
			//cout<<num.size()<<" , "<<lst<<endl;
			for(k=0;k<vt[lst].size();k++)
			{
				if(num[vt[lst][k]].S==(s[i][j]-'0'))
				{
					break;
				}
			}
			if(k<vt[lst].size())
			{
				lst=vt[lst][k];
				continue;
			}
			if(!vis[j+1][s[i][j]-'0'])
			{
				hv=false;
			}
			vis[j+1][s[i][j]-'0']=true;
			num.push_back(make_pair(j+1,s[i][j]-'0'));
			vt[lst].push_back(num.size()-1);
			lst=(ll)num.size()-1;
		}
		val[lst]+=app[i];
	}
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",dfs(0,0,m,0));
	return 0;
}
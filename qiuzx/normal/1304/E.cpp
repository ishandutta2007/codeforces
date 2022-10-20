#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,dp[N],f[N][32];
map<pair<ll,ll>,ll> mp;
vector<ll> vt[N];
void dfs(ll x,ll lst,ll d)
{
	ll i;
	dp[x]=d;
	for(i=0;i<30;i++)
	{
		f[x][i+1]=f[f[x][i]][i];
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			f[vt[x][i]][0]=x;
			dfs(vt[x][i],x,d+1);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	ll i;
	if(dp[x]<dp[y])
	{
		swap(x,y);
	}
	for(i=30;i>=0;i--)
	{
		if(dp[f[x][i]]>=dp[y])
		{
			x=f[x][i];
		}
		if(x==y)
		{
			return x;
		}
	}
    for(i=30;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
ll getdist(ll st,ll to)
{
	if(st==to)
	{
		return 0;
	}
	if(mp[make_pair(st,to)]!=0)
	{
		return mp[make_pair(st,to)];
	}
	ll lca=glca(st,to);
	mp[make_pair(st,to)]=dp[to]+dp[st]-2*dp[lca];
	return mp[make_pair(to,st)]=dp[to]+dp[st]-2*dp[lca];
}
int main(){
	ll i,x,y,q,a,b,k,d1,d2,d3,d4,d5;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
		mp[make_pair(x,y)]=1;
		mp[make_pair(y,x)]=1;
	}
	dfs(0,-1,0);
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>a>>b>>k;
		a--;
		b--;
		x--;
		y--;
		d1=getdist(a,b);
		d2=getdist(a,x);
		d3=getdist(a,y);
		d4=getdist(b,x);
		d5=getdist(b,y);
	//	cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<" "<<d5<<endl;
		if((d1<=k&&d1%2==k%2)||(d2+1+d5<=k&&(d2+1+d5)%2==k%2)||(d3+1+d4<=k&&(d3+1+d4)%2==k%2)||(d2+d4<=k&&(d2+d4)%2==k%2)||(d3+d5<=k&&(d3+d5)%2==k%2))
		{
			cout<<"YES"<<endl; 
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
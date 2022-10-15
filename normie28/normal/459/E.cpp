#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define mod 1000000009
#define fs(x,y) for(int i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
 
ll n,m,ar[N],sum,dp[N],last[N],tutmac[N];
 
pair<lli,ll> p[N];
 
bool cmp(pair<lli,ll> a,pair<lli,ll> b)
{
	return a.se<b.se;
}
 
int main()
{
	fast;
	cin>>n>>m;
	fo(i,1,m)
		cin>>p[i].fi.fi>>p[i].fi.se>>p[i].se;
	sort(p+1,p+m+1,cmp);
	fo(i,1,m)
	{
		ll a=p[i].fi.fi;
		ll b=p[i].fi.se;
		ll x=p[i].se;
		// cout<<endl;
		// cout<<a<<sp<<b<<sp<<x<<endl;
		// cout<<a<<sp<<b<<sp<<sp<<tutmac[a]<<sp<<tutmac[b]<<sp<<endl;
		if(x==tutmac[a])
		{
			if(dp[b]<last[a]+1)
			{
				if(tutmac[b]!=x)
					last[b]=dp[b],tutmac[b]=x;
				dp[b]=last[a]+1;
			}
 
		}
		else
		{
			if(dp[b]<dp[a]+1)
			{
				if(tutmac[b]!=x)
					last[b]=dp[b],tutmac[b]=x;
				dp[b]=dp[a]+1;
			}	
		}
	}
	// cout<<endl<<endl;
	fo(i,1,n)
	{
		sum=max(sum,dp[i]);
		// cout<<dp[i]<<endl;
	}
	// cout<<endl;
	cout<<sum;
}
//natsugiri
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll dp[130],lst[130],n,k,p,s[100010][8];
vector<pair<ll,ll> > a;
int main(){
	ll i,j,mask,x,left;
	cin>>n>>p>>k;
	left=n-p-k;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(make_pair(x,i));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			cin>>s[i][j];
		}
	}
	sort(a.begin(),a.end());
	memset(dp,-127,sizeof(dp));
	memset(lst,-127,sizeof(lst));
	lst[0]=0;
	for(i=0;i<n;i++)
	{
		for(mask=0;mask<(1<<p);mask++)
		{
			if(i-__builtin_popcount(mask)>=left)
			{
				dp[mask]=max(dp[mask],lst[mask]+a[i].F);
			}
			dp[mask]=max(dp[mask],lst[mask]);
			for(j=0;j<p;j++)
			{
				if((mask&(1<<j))==0)
				{
					dp[mask|(1<<j)]=max(dp[mask|(1<<j)],lst[mask]+s[a[i].S][j]);
				}
			}
		}
		swap(lst,dp);
		memset(dp,-127,sizeof(dp));
	}
	cout<<lst[(1<<p)-1]<<endl;
	return 0;
}
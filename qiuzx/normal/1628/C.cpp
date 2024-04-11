//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1010
using namespace std;
ll n,a[N][N],ans;
void solve(ll l1,ll r1,ll l2,ll r2,ll t)
{
	ll i;
	vector<pair<ll,ll> > allv;
	for(i=r1;i<=r2;i++)
	{
		if(((i^l1)&1)==t)
		{
			allv.push_back(make_pair(l1,i));
		}
	}
	for(i=l1+1;i<=l2;i++)
	{
		if(((i^r2)&1)==t)
		{
			allv.push_back(make_pair(i,r2));
		}
	}
	for(i=r2-1;i>=r1;i--)
	{
		if(((i^l2)&1)==t)
		{
			allv.push_back(make_pair(l2,i));
		}
	}
	for(i=l2-1;i>l1;i--)
	{
		if(((i^r1)&1)==t)
		{
			allv.push_back(make_pair(i,r1));
		}
	}
	for(i=0;i<allv.size();i+=2)
	{
		ans^=a[allv[i].F][allv[i].S];
	}
	if(l2-l1+1<=4)
	{
		return;
	}
	solve(l1+2,r1+2,l2-2,r2-2,t);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		ans=0;
		solve(0,0,n-1,n-1,0);
		solve(0,0,n-1,n-1,1);
		cout<<ans<<endl;
	}
	return 0;
}
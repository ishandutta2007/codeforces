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
#define N 100010
using namespace std;
ll n,q;
void solve()
{
	ll i,l=0,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(mid*(mid-1)/2<=n-mid)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<max(n-ans+ans*(ans-1)/2,2*n-2*ans-2)<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>q;
	while(q--)
	{
		cin>>n;
		solve();
	}
	return 0;
}
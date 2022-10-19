//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC target("f16c,xop,fma,fma4,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N];
map<ll,ll> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ll sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sum*=2;
		if(sum%n>0)
		{
			cout<<"0\n";
			continue;
		}
		sum/=n;
		mp.clear();
		ll ans=0;
		for(i=0;i<n;i++)
		{
			ans+=mp[sum-a[i]];
			mp[a[i]]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
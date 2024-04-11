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
ll n,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ll s=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		cout<<((s%n==0)?0:1)<<endl;
	}
	return 0;
}
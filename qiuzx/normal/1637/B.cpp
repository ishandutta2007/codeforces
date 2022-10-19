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
#define N 110
using namespace std;
ll n,a[N],sum[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<=n+5;i++)
		{
			sum[i]=0;
		}
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum[i+1]=sum[i]+(a[i]==0);
		}
		ll ans=0;
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				ans+=sum[j+1]-sum[i]+j-i+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
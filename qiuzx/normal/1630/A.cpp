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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i;
	cin>>T;
	while(T--)
	{
		ll n,k;
		cin>>n>>k;
		if(k==n-1&&n==4)
		{
			cout<<"-1"<<endl;
			continue;
		}
		else if(k==n-1)
		{
			cout<<0<<" "<<n-4<<endl;
			cout<<1<<" "<<3<<endl;
			cout<<n-2<<" "<<n-1<<endl;
			for(i=2;i<n-2;i++)
			{
				if(i<n/2&&i!=3)
				{
					cout<<i<<" "<<n-i-1<<endl;
				}
			}
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				cout<<0<<" "<<n-k-1<<endl;
			}
			else if(i==k)
			{
				cout<<k<<" "<<n-1<<endl;
			}
			else if(i<n/2&&i!=n-k-1)
			{
				cout<<i<<" "<<n-i-1<<endl;
			}
		}
	}
	return 0;
}
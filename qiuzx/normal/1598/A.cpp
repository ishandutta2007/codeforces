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
#define N 100010
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,n,i;
	string s,t;
	cin>>T;
	while(T--)
	{
		cin>>n>>s>>t;
		for(i=0;i<n;i++)
		{
			if(s[i]=='1'&&t[i]=='1')
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	return 0;
}
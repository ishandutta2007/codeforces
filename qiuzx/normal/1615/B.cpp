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
#define N 200010
using namespace std;
ll n,l,r,ans,f[N][20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,T;
	for(i=1;i<N;i++)
	{
		for(j=0;j<20;j++)
		{
			f[i][j]=f[i-1][j]+((i&(1<<j))?1:0);
		}
	}
	cin>>T;
	while(T--)
	{
		cin>>l>>r;
		ans=LINF;
		for(i=0;i<20;i++)
		{
			ans=min(ans,r-l+1-f[r][i]+f[l-1][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
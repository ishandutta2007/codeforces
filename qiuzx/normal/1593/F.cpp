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
#define N 42
using namespace std;
ll n,a,b,ans;
bitset<90> dp[N][N][N];
string s;
void print_path(ll x,ll j,ll k,ll plc)
{
	if(x==0)
	{
		return;
	}
	ll i;
	for(i=0;i<max(a,b);i++)
	{
		if((i*10+(s[x-1]-'0'))%a==j&&dp[x-1][i][k][plc-1])
		{
			print_path(x-1,i,k,plc-1);
			putchar('R');
			return;
		}
		else if((i*10+(s[x-1]-'0'))%b==k&&dp[x-1][j][i][plc+1])
		{
			print_path(x-1,j,i,plc+1);
			putchar('B');
			return;
		}
	}
	return;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	ll T,i,j,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b>>s;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=max(a,b);j++)
			{
				for(k=0;k<=max(a,b);k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		dp[0][0][0][N]=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<a;j++)
			{
				for(k=0;k<b;k++)
				{
					dp[i+1][(j*10+(s[i]-'0'))%a][k]|=(dp[i][j][k]<<1);
					dp[i+1][j][(k*10+(s[i]-'0'))%b]|=(dp[i][j][k]>>1);
				}
			}
		}
		ans=LINF;
		k=-1;
		for(i=0;i<90;i++)
		{
			if(dp[n][0][0][i])
			{
				if(ans>abs(i-N))
				{
					ans=abs(i-N);
					k=i;
				}
			}
		}
		if(ans>=n)
		{
			cout<<"-1\n";
			continue;
		}
		print_path(n,0,0,k);
		cout<<"\n";
	}
	return 0;
}
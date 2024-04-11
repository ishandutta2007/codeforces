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
ll n,t[N],h[N],dp[N],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j,cur,lst;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			dp[i]=LINF;
			cin>>t[i];
		}
		for(i=1;i<=n;i++)
		{
			cin>>h[i];
		}
		t[0]=h[0]=0;
		dp[0]=0;
		for(i=0;i<n;i++)
		{
			ll mnt=LINF;
			for(j=i+1;j<=n;j++)
			{
				mnt=min(mnt,t[j]-h[j]);
				if(mnt<t[i])
				{
					break;
				}
				dp[j]=min(dp[j],dp[i]+(t[j]-mnt)*(t[j]-mnt+1)/2);
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
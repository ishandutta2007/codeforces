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
#define N 1010
using namespace std;
ll n,a[N][5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,n,i,j,k;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			{
				cin>>a[i][j];
			}
		}
		bool ans=false;
		for(j=0;j<5;j++)
		{
			for(k=j+1;k<5;k++)
			{
				ll n1=0,n2=0,n3=0;
				for(i=0;i<n;i++)
				{
					if(a[i][j]&&a[i][k])
					{
						n1++;
					}
					else if(a[i][j])
					{
						n2++;
					}
					else if(a[i][k])
					{
						n3++;
					}
					else
					{
						i=-1;
						break;
					}
				}
				if(i>=0&&n2<=n/2&&n3<=n/2)
				{
					ans=true;
				}
			}
		}
		if(ans)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
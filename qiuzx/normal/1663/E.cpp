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
ll n,dist[N][N],dx[]={0,1,1},dy[]={1,0,1};
string grid[N],ans="theseus";
int main(){
	ll i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>grid[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j+7<=n)
			{
				string s="";
				for(k=0;k<7;k++)
				{
					s+=grid[i][j+k];
				}
				if(s=="theseus")
				{
					puts("YES");
					return 0;
				}
			}
			if(i+7<=n)
			{
				string s="";
				for(k=0;k<7;k++)
				{
					s+=grid[i+k][j];
				}
				if(s=="theseus")
				{
					puts("YES");
					return 0;
				}
			}
			if(i+7<=n&&j+7<=n)
			{
				string s="";
				for(k=0;k<7;k++)
				{
					s+=grid[i+k][j+k];
				}
				if(s=="theseus")
				{
					puts("YES");
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}
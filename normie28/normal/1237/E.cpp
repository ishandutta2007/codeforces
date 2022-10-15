#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll dp[2001][2][2],n,i,j,k,t,t1,u,v,a,b,l,r;
map<ll,ll> res;
int main()
{
	cin>>n;
	u=1;
	v=2;
	while (u<=1000000)
	{
		res[u]=1;
		res[v]=1;
		if (u%2==1)
		{
			a=v*2;
		}
		else 
		{
			a=v*2-1;
		}
		b=a+1;
		u=a;
		v=b;
	}
	cout<<res[n];
}
/*
1 2 4 5 9 10 20 21 41 42 84 85 169 170 340 341 681 682
*/
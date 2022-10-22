// Author: Little09
// Problem: CF932E Team Work
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF932E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
const ll mod=1000000007;

const int N=5005;
int n,k; 
ll s[N][N];
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	s[0][0]=1;
	cin >> n >> k;
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=i;j++)
		{
			s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j])%mod;
		}
	}
	ll ans=0;
	ll tot=ksm(2,n),tmp=ksm(2,mod-2);
	for (int j=0;j<=k;j++)
	{
		if (j>n) break;
		ans=(ans+tot*s[k][j]%mod)%mod;
		tot=tot*(n-j)%mod;
		tot=tot*tmp%mod;
	}
	cout << ans;
	return 0;
}
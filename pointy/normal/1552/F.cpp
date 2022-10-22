// By: Little09
// Problem: F. Telepanting
// Contest: Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N],b[N],c[N];
ll s[N],dp[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		ll res=0;
		int u=lower_bound(a+1,a+n+1,b[i])-a;
		res=(res+s[i-1]-s[u-1]+mod)%mod;
		res=(res+a[i]-b[i])%mod;
		dp[i]=res,s[i]=(s[i-1]+res)%mod;
	}
	ll ans=(a[n]+1)%mod;
	for (int i=1;i<=n;i++)
	{
		if (c[i]==1) ans=(ans+dp[i])%mod;
	}
	cout << ans;
	return 0;
}
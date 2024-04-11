// By: Little09
// Problem: D2. Game on Sum (Easy Version)
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/D2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
const ll mod=1000000007;

const int N=1000005;
ll n,m,k; 
ll dp[N];

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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
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
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x||y<0) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	dp[1]=ksm(2,mod-2);
	for (int i=2;i<=N-3;i++) dp[i]=dp[i-1]*dp[1]%mod;
}
void work()
{
	n=read(),m=read(),k=read();
	ll ans=0;
	if (n==m)
	{
		ans=k*n%mod;
		cout << ans << endl;
		return;
	}
	for (ll i=1;i<n;i++)
	{
		ans=(ans+i*C(n-1-i,m-i)%mod*dp[n-i]%mod*k%mod)%mod;
	}
	cout << ans << endl;
	return;
}

int main()
{
	init();
	int T=read();
	while (T--) work();
	return 0;
}
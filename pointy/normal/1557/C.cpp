// By: Little09
// Problem: C. Moamen and XOR
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/C
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
int a[N];

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
int k;
const ll mod=1000000007;
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
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
void work()
{
	n=read(),k=read();
	if (n%2==1)
	{
		ll ans=C(n,0);
		for (int i=1;i<=n;i+=2) ans=(ans+C(n,i))%mod;
		ans=ksm(ans,k)%mod;
		cout << ans << endl;
		return;
	}
	else
	{
		ll res=0,ans=0,t=ksm(2,n);
		for (int i=2;i<=n;i+=2) res=(res+C(n,i))%mod;
		for (int i=1;i<=k;i++) 
		{
			ans=(ans+ksm(res,i-1)*ksm(t,k-i)%mod)%mod;
		}
		ans=(ans+ksm(res,k))%mod;
		cout << ans << endl;
	}
	return;
}

int main()
{
	init();
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}
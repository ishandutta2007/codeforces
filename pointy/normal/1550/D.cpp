#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 
const ll mod=1000000007;
//const ll mod=998244353;

const int N=1000005,B=400001;
ll n,l,r;
int T; 
int a[N];
ll s[N],mul[N];

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
	if (y<0) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
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

ll js(ll x,ll y)
{
	if (x+y<n) return 0;
	ll p=x+y-n;
	if (n%2==0) return C(p,n/2-(x-p));
	return (C(p,n/2-(x-p))+C(p,n/2+1-(x-p)))%mod;
}

void work()
{
	n=read(),l=read(),r=read();
	ll l1=l-n,l2=l-1,r1=r-n,r2=r-1,res=0;
	if (r1>-l2)
	{
		ll x=-l2-r1;
		l1+=x,l2+=x,r1+=x,r2+=x;
	}
	res=(res+r1*C(n,n/2)%mod)%mod;
	if (n%2==1) res=(res+r1*C(n,n/2)%mod)%mod;
	for (int i=r1+1;i<=r2;i++)
	{
		ll u1=r2-i+1,u0;
		if (-i>=l2) u0=n;
		else u0=n-(l2-(-i));
		res=(res+js(u0,u1))%mod;
	}
	cout << res << endl;
	return;
}

int main()
{
	init();
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}
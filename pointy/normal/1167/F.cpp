#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
inline ll read()
{
    ll F=1,ANS=0;
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
const ll N=1000005;
const ll mod=1000000007;
ll tree[N][2];
inline ll lowbit(ll x)
{
	return x&(-x);
}
inline void add(ll x,ll k,ll t)
{
	if (t==1) x=n-x+1;
	for (;x<=n;x+=lowbit(x)) tree[x][t]=(tree[x][t]+k)%mod;
}
inline ll ask(ll x,ll t)
{
	if (t==1) x=n-x+1;
	ll ans=0;
	for (;x;x-=lowbit(x)) ans=(ans+tree[x][t])%mod;
	return ans;
}
ll a[N];
ll s[N][2],ans;
struct poll
{
	ll x,id;
}b[N];
bool cmp(poll x,poll y)
{
	return x.x<y.x;
}
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	n=read();
	for (ll i=1;i<=n;i++) a[i]=read(),b[i].x=a[i],b[i].id=i;
	for (ll i=1;i<=n;i++) add(i,a[i]*(n-i+1)%mod,1);
	for (ll i=1;i<=n;i++) add(i,a[i]*i%mod,0);
	sort(b+1,b+n+1,cmp);
	for (ll i=1;i<=n;i++)
	{
		ll l=b[i].id,r=n-l+1;
		ans=(ans+l*r%mod*((ll)a[l]))%mod;
		ans=(ans+r*ask(l-1,0)%mod)%mod;
		ans=(ans+l*ask(l+1,1)%mod)%mod;
		add(l,-a[l]*(n-l+1)%mod,1);
		add(l,-a[l]*l%mod,0);
	}
	cout << ans;
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
const ll base=1145141;
const ll Add=19260817;
const ll Mod=1919810111;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll gcd(ll x,ll y)
{
	return !y?x:gcd(y,x%y);
}
ll Hash(vector<ll>&a)
{
	ll ret=0;
	for (ll i:a) ret=(ret*base+i+Add)%Mod;
	return ret;
}
ll a[N];
vector<ll>H[N];
map<ll,ll>b;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll T=read();
	while (T--)
	{
		ll n=read(),m=read();
		b.clear();
		for (ll i=1;i<=n;i++) H[i].clear();
		for (ll i=1;i<=n;i++) a[i]=read();
		for (ll i=1;i<=m;i++)
		{
			ll u=read(),v=read();
			H[v].push_back(u);
		}
		for (ll i=1;i<=n;i++) sort(H[i].begin(),H[i].end());
		for (ll i=1;i<=n;i++) b[Hash(H[i])]+=a[i];
		ll ans=0;
		for (auto i:b) if (i.first) ans=gcd(ans,i.second);
		print(ans);
	}
	
	return 0;
}
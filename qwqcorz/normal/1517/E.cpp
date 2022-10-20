#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
const ll inf=1LL<<60;
const ll p=998244353;

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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
inline void add(ll &x,ll y)
{
	x+=y;
	if (x>=p) x-=p;
}
struct BIT
{
	ll t[N*2],n;
	void send(ll _n) {
		n=_n;
		for (ll i=0;i<=n;i++) t[i]=0;
	}
	void add(ll x) {
		for (;x<=n;x+=x&-x) t[x]++;
	}
	ll query(ll x) {
		ll ret=0;
		for (;x;x-=x&-x) ret+=t[x];
		return ret;
	}
}t;
ll a[N],b[N],c[N],d[N*2];
ll Lsum[N],Rsum[N],sum[N];
inline ll count(ll l,ll r)//bi-cj>0,i>=j,((i-j)&1)=0
{
	ll cnt=0;
	for (ll i=l;i<=r;i++)
	{
		d[++cnt]=b[i];
		d[++cnt]=c[i];
	}
	sort(d+1,d+1+cnt);
	cnt=unique(d+1,d+1+cnt)-d-1;
	for (ll i=l;i<=r;i++)
	{
		b[i]=lower_bound(d+1,d+1+cnt,b[i])-d;
		c[i]=lower_bound(d+1,d+1+cnt,c[i])-d;
	}
	ll ret=0;
	t.send(cnt);
	for (ll i=l;i<=r;i++)
	if (i&1)
	{
		t.add(c[i]);
		add(ret,t.query(b[i]-1));
	}
	t.send(cnt);
	for (ll i=l;i<=r;i++)
	if (~i&1)
	{
		t.add(c[i]);
		add(ret,t.query(b[i]-1));
	}
	return ret;
}
inline ll solve(ll l,ll r,bool L,bool R,ll Add)
{
	if (l-1>r) return 0;
	if (L) return solve(l+2,r,0,R,Add-a[l]-a[l+1]);
	if (R) return solve(l,r-2,L,0,Add+a[r]+(r?a[r-1]:0));
	if (l>r) return Add>0;
	Lsum[l-1]=Lsum[r+1]=Rsum[l-1]=Rsum[r+1]=sum[l-1]=sum[r+1]=0;
	for (ll i=l;i<=r;i++) Lsum[i]=Lsum[i-1]+a[i];
	for (ll i=r;i>=l;i--) Rsum[i]=Rsum[i+1]+a[i];
	sum[l]=0;
	for (ll i=l+1;i<=r;i++) sum[i]=sum[i-2]+a[i-1]-a[i];
	for (ll i=l-1;i<=r;i++) c[i]=Lsum[i]+sum[i];
	for (ll i=l-1;i<=r;i++) b[i]=sum[i]+Rsum[i+1];
	for (ll i=l-1;i<=r;i++) b[i]+=Add;
	return count(l-1,r);
}

signed main()
{
	ll T=read();
	while (T--)
	{
		ll n=read(),ans=0;
		for (ll i=1;i<=n;i++) a[i]=read();
		Lsum[0]=Lsum[n+1]=Rsum[0]=Rsum[n+1]=sum[0]=sum[n+1]=0;
		for (ll i=1;i<=n;i++) Lsum[i]=Lsum[i-1]+a[i];
		for (ll i=n;i>=1;i--) Rsum[i]=Rsum[i+1]+a[i];
		for (ll i=2;i<=n-2;i++) if (Lsum[i]>Rsum[i+1]) ans++;//print(ans);
		add(ans,solve(1,n,0,0,0));//print(ans);
		add(ans,solve(2,n,1,0,a[1]));//print(ans);
		add(ans,solve(1,n-1,0,1,-a[n]));//print(ans);
		add(ans,solve(2,n-1,1,1,a[1]-a[n]));
		print(ans);
	}

	return 0;
}
//1145141919810
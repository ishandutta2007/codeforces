#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5+15;
const ll inf=1LL<<60;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll Div(ll x,ll y)
{
	return (x+y-1)/y;
}
ll m,n,k,a[N],L,R;
ll check1(ll mid)
{
	ll ret=0;
	for (ll i=1;i<=n;i++) ret+=Div(a[i],mid)-1;
	return ret;
}
ll check2(ll mid)
{
	ll ret=0;
	for (ll i=1;i<=n;i++) ret+=a[i]/mid-1;
	return ret;
}
void YSGS()
{
	ll l=1,r=m;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (check1(mid)<=k) r=mid-1;
					   else l=mid+1;
	}
	R=l;
	l=1,r=m;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (check2(mid)>=k) l=mid+1;
					   else r=mid-1; 
	}
	L=r;
}
struct node
{
	ll L,R;
	bool operator <(const node &a)const
	{
		return L<a.L||(L==a.L&&R<a.R);
	}
}b[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll T=read();
	while (T--)
	{
		m=read(),n=read(),k=read();
		for (ll i=1;i<=n;i++) a[i]=read();
		a[++n]=m;
		for (ll i=n;i>=1;i--) a[i]=a[i]-a[i-1];
		YSGS();
		if (R<=L) puts("0");
		else
		{
			ll cnt=0;
			b[++cnt]=(node){-inf,R};
			b[++cnt]=(node){L,inf};
			for (ll i=1;i<=n;i++)
			if (a[i]/L-Div(a[i],R)<0)
			{
				b[++cnt]=(node){a[i]/Div(a[i],R),a[i]/L?Div(a[i],a[i]/L):inf};
			}
			sort(b+1,b+1+cnt);
			ll ans=inf;
			for (ll i=2;i<=cnt;i++) b[i].R=max(b[i].R,b[i-1].R);
			for (ll i=1;i<cnt;i++) ans=min(ans,b[i].R-b[i+1].L);
			print(ans);
		}
	}

	return 0;
}
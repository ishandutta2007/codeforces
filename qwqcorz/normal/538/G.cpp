#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5+5;
const ll L=2e6+5;
const ll inf=1e9+7;

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
void error()
{
	puts("NO");
	exit(0);
}
inline ll f(ll x)
{
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}
ll t[N],x[N],y[N],n,l,ans[2][L];
struct node
{
	ll k,b,x;
	bool operator <(const node &a)const
	{
		return b<a.b;
	}
}a[N];
void solve(ll *x,ll *ans)
{
	for (ll i=1;i<l;i++) ans[i]=inf;
	for (ll i=1;i<=n;i++)
	{
		a[i].k=t[i]/l;
		a[i].b=t[i]%l;
		a[i].x=x[i];
	}
	ll cnt=n+1;
	a[cnt]=(node){-1,l,0};
	sort(a+1,a+1+cnt);
	ll L=-inf,R=inf;
	for (ll i=0;i<cnt;i++)
	if (a[i+1].k!=a[i].k)
	{
		if (a[i].k-a[i+1].k>0)
		{
			L=max(L,(ll) ceil(1.0L*(a[i].x-a[i+1].x)/(a[i].k-a[i+1].k)));
			R=min(R,(ll)floor(1.0L*(a[i].x-a[i+1].x+a[i+1].b-a[i].b)/(a[i].k-a[i+1].k)));
		}
		else
		{
			L=max(L,(ll) ceil(1.0L*(a[i+1].x-a[i].x+a[i].b-a[i+1].b)/(a[i+1].k-a[i].k)));
			R=min(R,(ll)floor(1.0L*(a[i+1].x-a[i].x)/(a[i+1].k-a[i].k)));
		}
	}
	//xi=Sn*(ti/l)+S[ti%l]
	//xi=Sn*k+Sb
	//Sb=xi-Sn*k
	//Si-Sj<=i-j
	//i>=j
	//0<=xi-Sn*ki-xj+Sn*kj<=i-j
	///////////////////////////////////
	//1:Sn*(kj-ki)<=i-j+xj-xi
	//1:Sn*(kj-ki)>=xj-xi
	///////////////////////////////////
	//2:Sn*(ki-kj)>=j-i+xi-xj
	//2:Sn*(ki-kj)<=xi-xj
	if (L>R) error();
	if (L==-inf&&R==inf)
	{
		ans[l]=inf;
		for (ll i=1;i<=cnt;i++) ans[a[i].b]=a[i].x;
	}
	else
	{
		ll Sn=L;
		ans[l]=Sn;
		for (ll i=1;i<=cnt;i++) ans[a[i].b]=a[i].x-Sn*a[i].k;
	}
	for (ll i=1,j=0;i<=l;i++)
	if (ans[i]<inf)
	{
		if (ans[i]-ans[j]>i-j||ans[i]<ans[j]) error();
		while (ans[j]!=ans[i]&&j<i) ans[j+1]=ans[j]+1,j++;
		while (j<i) ans[j+1]=ans[j],j++;
		j=i;
	}
	if (L==-inf&&R==inf) for (ll i=1;i<=l;i++) if (ans[i]==inf) ans[i]=ans[i-1];
	for (ll i=l;i>=1;i--) ans[i]=ans[i]-ans[i-1];
}

signed main()
{
	n=read(),l=read();
	for (ll i=1;i<=n;i++)
	{
		t[i]=read();
		ll tmpx=read(),tmpy=read();
		if ((tmpx+tmpy+t[i])%2) error();
		x[i]=(tmpx+tmpy+t[i])/2;
		y[i]=(tmpy-tmpx+t[i])/2;
	}
	solve(x,ans[0]);
	solve(y,ans[1]);
	for (ll i=1;i<=l;i++)
	{
		if (ans[0][i]&&ans[1][i]) putchar('U');
		if (ans[0][i]&&!ans[1][i]) putchar('R');
		if (!ans[0][i]&&ans[1][i]) putchar('L');
		if (!ans[0][i]&&!ans[1][i]) putchar('D');
	}
	
	return 0;
}
/*
3 4
1 1 0
2 1 -1
7 0 -1
RDLU
*/
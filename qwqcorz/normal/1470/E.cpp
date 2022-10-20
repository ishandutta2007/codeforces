#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e4+5;
const ll C=5;

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
ll Ca[N][C];
ll calc(ll n,ll m)
{
	n--;
	if (n<0||m<0) return 1;
	return Ca[n][m];
}
struct node
{
	ll l,r,w;
}a[C][N*C*2];
ll L[C][N],R[C][N],p[N],sum[C][N*C*2];
void clear(ll n)
{
	for (ll k=1;k<=4;k++)
	{
		for (ll i=L[k][0];i<=R[k][0];i++) sum[k][i]=0;
		a[k][L[k][0]=R[k][0]=N*C]=(node){n,n,1};
	}
}
node get(ll i,ll c,ll y)
{
	ll l=L[c][i],r=R[c][i];
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (sum[c][mid]-sum[c][L[c][i]-1]>=y) r=mid-1;
										 else l=mid+1;
	}
	assert(L[c][i]<=l&&l<=R[c][i]);
	return (node){a[c][l].l,a[c][l].r,sum[c][l-1]-sum[c][L[c][i]-1]};
}
ll query(ll x,ll y,ll c,ll up)
{
	if (y>up) return -1;
	ll now=1;
	while ("asdf")
	{
		node s=get(now,c,y);
		if (x<s.l) return p[x];
		if (x<=s.r) return p[s.l+s.r-x];
		if (!(c-=s.r-s.l)) return p[x];
		now=s.r+1;
		y-=s.w;
	}
	return 0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	for (ll i=Ca[0][0]=1;i<N;i++)
	for (ll j=Ca[i][0]=1;j<C;j++) Ca[i][j]=Ca[i-1][j-1]+Ca[i-1][j];
	for (ll i=0;i<N;i++)
	for (ll j=1;j<C;j++) Ca[i][j]+=Ca[i][j-1];
	ll T=read();
	while (T--)
	{
		ll n=read(),c=read(),q=read(),up=calc(n,c);clear(n);
		for (ll i=1;i<=n;i++) p[i]=read();
		for (ll i=n;i>=1;i--)
		for (ll k=1;k<=4;k++)
		{
			int tmpl=L[k][0],tmpr=R[k][0];
			for (ll j=i+1;j<=i+k&&j<=n;j++)
			if (p[j]<p[i]) a[k][--L[k][0]]=(node){i,j,calc(n-j,k-(j-i))};
					  else a[k][++R[k][0]]=(node){i,j,calc(n-j,k-(j-i))};
			L[k][i]=L[k][0];
			R[k][i]=R[k][0];
			sort(a[k]+L[k][0],a[k]+tmpl,[&](const node &x,const node &y){return p[x.r]<p[y.r];});
			sort(a[k]+tmpr+1,a[k]+R[k][0]+1,[&](const node &x,const node &y){return p[x.r]<p[y.r];});
		}
		for (ll k=1;k<=4;k++)
		for (ll i=L[k][0];i<=R[k][0];i++)
		sum[k][i]=sum[k][i-1]+a[k][i].w;
//		for (int i=L[4][0];i<=R[4][0];i++)
//		print(a[4][i].l,' '),print(a[4][i].r,':'),print(a[4][i].w);
//		print(up);
//		print(sum[4][R[4][0]]);
		while (q--)
		{
			ll x=read(),y=read();
			print(query(x,y,c,up));
		}
	}
	
	return 0;
}
/*
1
6 4 1
6 1 4 2 5 3 
5 2
*/
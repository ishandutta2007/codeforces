#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int B;
struct Change{int t,x,y;}c[N];
struct Query
{
	int t,x,y;
	bool operator <(const Query &a)const
	{
		return y/B!=a.y/B?y<a.y:((y/B)&1)?t>a.t:t<a.t;
	}
}q[N];
int a[N],b[N*2],cnt=0,cntc=0,cntq=0,ans[N],sum[N],tot[N*2];
void add(int x){sum[++tot[x]]++;}
void del(int x){sum[tot[x]--]--;}
void change(int t,int r)
{
	if (c[t].x<=r) del(a[c[t].x]);
	swap(a[c[t].x],c[t].y);
	if (c[t].x<=r) add(a[c[t].x]);
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) b[++cnt]=a[i]=read();
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1) c[++cntc]=(Change){i,y,x},b[++cnt]=x;
		if (opt==2) q[++cntq]=(Query){i,x,y};
		ans[i]=-1;
	}
	B=sqrt(1.0*cntc*n/(1+cntq))*1.5+1;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	for (int i=1;i<=cntc;i++) c[i].y=lower_bound(b+1,b+1+cnt,c[i].y)-b;
	sort(q+1,q+1+cntq);
	for (int i=1,r=0,t=0;i<=cntq;i++)
	{
		while (r<q[i].y) add(a[++r]);
		while (r>q[i].y) del(a[r--]);
		while (t<cntc&&c[t+1].t<=q[i].t) change(++t,r);
		while (t&&c[t].t>q[i].t) change(t--,r);
		if (q[i].x==1) ans[q[i].t]=b[a[q[i].y]];
		else if (q[i].x%2==0) ans[q[i].t]=tot[a[q[i].y]];
		else ans[q[i].t]=sum[tot[a[q[i].y]]];
	}
	for (int i=1;i<=Q;i++) if (~ans[i]) print(ans[i]);
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;

int read()
{
	int s=0;
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
struct bit
{
	int t[N],n;
	void add(int x){for (;x;x-=x&-x) t[x]++;}
	int query(int x){int ret=0;for (;x<=n;x+=x&-x) ret+=t[x];return ret;}
}t;
namespace sgt
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void update(int w,int x)
	{
		t[w]+=x;
		tag[w]+=x;
	}
	void push_down(int w)
	{
		if (!tag[w]) return;
		update(ls,tag[w]);
		update(rs,tag[w]);
		tag[w]=0;
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (r<ql||qr<l) return;
		if (ql<=l&&r<=qr) return update(w,x);
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
		t[w]=min(t[ls],t[rs]);
	}
	#undef mid
	#undef rs
	#undef ls
}
struct node
{
	int o,val,pos;
}c[N];
int a[N],b[N],z[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		ll ans=0;
		int n=read(),m=read();
		for (int i=1;i<=n;i++) z[i]=a[i]=read();
		for (int i=1;i<=m;i++) z[n+i]=b[i]=read();
		sort(z+1,z+1+n+m);
		int cnt=t.n=unique(z+1,z+1+n+m)-z-1;
		for (int i=1;i<=n;i++) a[i]=lower_bound(z+1,z+1+cnt,a[i])-z;
		for (int i=1;i<=m;i++) b[i]=lower_bound(z+1,z+1+cnt,b[i])-z;
		for (int i=1;i<=n;i++) t.add(a[i]),ans+=t.query(a[i]+1);
		for (int i=1;i<=n;i++) c[i]=(node){0,a[i],i};
		for (int i=1;i<=m;i++) c[n+i]=(node){1,b[i],i};
		sort(c+1,c+1+n+m,[&](node x,node y){return x.val<y.val;});
		for (int i=1;i<=n;i++) sgt::add(1,0,n,i,n,1);
		for (int i=1,j=1;i<=n+m+1;i++)
		if (i>n+m||c[i].val!=c[j].val)
		{
			for (int k=j;k<i;k++) if (c[k].o==0) sgt::add(1,0,n,c[k].pos,n,-1);
			for (int k=j;k<i;k++) if (c[k].o==1) ans+=sgt::t[1];
			for (int k=j;k<i;k++) if (c[k].o==0) sgt::add(1,0,n,0,c[k].pos-1,1);
			j=i;
		}
		print(ans);
		memset(t.t,0,sizeof(int)*(cnt+1));
		memset(sgt::t,0,sizeof(int)*n*4+5);
		memset(sgt::tag,0,sizeof(int)*n*4+5);
	}
	
	return 0;
}
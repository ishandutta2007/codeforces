#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct dsu
{
	int fa[N],val[N],siz[N],st[N],top;
	void send(int n){top=0;for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,val[i]=0;}
	int getval(int x){return fa[x]==x?0:val[x]^getval(fa[x]);}
	int find(int x){return fa[x]==x?x:find(fa[x]);}
	bool merge(int x,int y)
	{
		int Xor=getval(x)^getval(y);
		x=find(x),y=find(y);
		if (x==y) return Xor;
		if (siz[x]>siz[y]) swap(x,y);
		fa[x]=y,siz[y]+=siz[x],val[x]=!Xor,st[++top]=x;
		return 1;
	}
	void roll_back(int k)
	{
		while (top>k)
		{
			int x=st[top--];
			siz[fa[x]]-=siz[x];
			val[x]=0,fa[x]=x;
		}
	}
}d;
int u[N],v[N],ans[N];
void solve(int l,int r,int ql,int qr)
{
	if (l>r) return;
	int mid=(l+r+1)/2,tmp=d.top;
	for (int i=l+1;i<=mid;i++) d.merge(u[i],v[i]);
	int tmp2=d.top,midq=ql-1;
	for (int i=qr;i>=ql;i--) if (!d.merge(u[i],v[i]))
	{
		midq=i;
		break;
	}
	ans[mid]=midq;
	d.roll_back(tmp2);
	if (l==r) return;
	solve(mid,r,midq,qr);
	d.roll_back(tmp);
	for (int i=qr;i>midq;i--) d.merge(u[i],v[i]);
	solve(l,mid-1,ql,midq);
	d.roll_back(tmp);
}

signed main()
{
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=m;i++) u[i]=read(),v[i]=read();
	d.send(n);
	int mid=m;
	for (int i=1;i<=m;i++) if (!d.merge(u[i],v[i]))
	{
		mid=i-1;
		for (int j=i;j<=m;j++) ans[j]=m+1;
		break;
	}
	d.roll_back(0);
	solve(0,mid,1,m);
	while (Q--)
	{
		int l=read(),r=read();
		puts(ans[l-1]<=r?"NO":"YES");
	}
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=3e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int u[M],v[M],w[M],ans[M];
struct dsu
{
	int st[N],top=0;
	int n,tot,fa[N],siz[N];
	void send(int _n){tot=n=_n;for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:find(fa[x]);}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y) return;
		if (siz[x]>siz[y]) swap(x,y);
		tot-=siz[x]%2+siz[y]%2;
		fa[x]=y,siz[y]+=siz[x];
		tot+=siz[y]%2;
		st[++top]=x;
	}
	void pop(int t)
	{
		while (top>t)
		{
			int x=st[top--],y=fa[x];
			tot-=siz[y]%2;
			siz[fa[x]]-=siz[x],fa[x]=x;
			tot+=siz[x]%2+siz[y]%2;
		}
	}
}d;
void cdq(int l,int r,int vl,int vr,vector<int>id)
{
	if (l>r) return;
//	print(l,','),print(r,'|'),print(vl,','),print(vr);
	if (vl==vr){for (int i=l;i<=r;i++) ans[i]=vl;return;}
	int mid=(vl+vr)/2,pos=r+1,tmp=d.top;
	vector<int>idl,idr;
	for (int i:id) (w[i]<=mid?idl:idr).push_back(i);
	for (int i:id) if (i<l&&w[i]<=mid) d.merge(u[i],v[i]);
	for (int i=l;i<=r;i++)
	{
		if (w[i]<=mid) d.merge(u[i],v[i]);
		if (!d.tot){pos=i;break;}
	}
	d.pop(tmp);
	for (int i:id) if (i<l&&w[i]<=mid) d.merge(u[i],v[i]);
	cdq(l,pos-1,mid+1,vr,idr);
	d.pop(tmp);
	for (int i=l;i<pos;i++) if (w[i]<vl) d.merge(u[i],v[i]);
	cdq(pos,r,vl,mid,idl);
	d.pop(tmp);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++) u[i]=read(),v[i]=read(),w[i]=read();
	vector<int>id; for (int i=1;i<=m;i++) id.push_back(i);
	d.send(n);
	cdq(1,m,1,1e9+1,id);
	for (int i=1;i<=m;i++) print(ans[i]<=1e9?ans[i]:-1);
	
	return 0;
}
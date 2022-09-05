#include<bits/stdc++.h>
using namespace std;

int n,a[200010],ans[200010];
vector<int> v[200010];

struct seg
{
	struct node{int l,r,mi,ma,laz;}t[800010];
	void build(int i,int l,int r,bool o)
	{
		t[i].l=l,t[i].r=r,t[i].laz=0;
		if (l==r) {t[i].mi=t[i].ma=(o?n-l+1:l); return;}
		int mid=(l+r)>>1;
		build(i<<1,l,mid,o),build(i<<1|1,mid+1,r,o);
		t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
		t[i].ma=max(t[i<<1].ma,t[i<<1|1].ma);
	}
	void pushdown(int i)
	{
		if (!t[i].laz) return;
		t[i<<1].laz+=t[i].laz,t[i<<1].mi+=t[i].laz,t[i<<1].ma+=t[i].laz;
		t[i<<1|1].laz+=t[i].laz,t[i<<1|1].mi+=t[i].laz,t[i<<1|1].ma+=t[i].laz;
		t[i].laz=0;
	}
	void add(int i,int l,int r,int v)
	{
		if (t[i].l==l&&t[i].r==r) {t[i].mi+=v,t[i].laz+=v,t[i].ma+=v; return;}
		int mid=(t[i].l+t[i].r)>>1; pushdown(i);
		if (r<=mid) add(i<<1,l,r,v); else
		if (l>mid) add(i<<1|1,l,r,v); else
		add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
		t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
		t[i].ma=max(t[i<<1].ma,t[i<<1|1].ma);
	}
	int query_mi(int i,int l,int r)
	{
		if (l>r) return 0;
		if (t[i].l==l&&t[i].r==r) return t[i].mi;
		int mid=(t[i].l+t[i].r)>>1; pushdown(i);
		if (r<=mid) return query_mi(i<<1,l,r);
		if (l>mid) return query_mi(i<<1|1,l,r);
		return min(query_mi(i<<1,l,mid),query_mi(i<<1|1,mid+1,r));
	}
	int query_ma(int i,int l,int r)
	{
		if (l>r) return 0;
		if (t[i].l==l&&t[i].r==r) return t[i].ma;
		int mid=(t[i].l+t[i].r)>>1; pushdown(i);
		if (r<=mid) return query_ma(i<<1,l,r);
		if (l>mid) return query_ma(i<<1|1,l,r);
		return max(query_ma(i<<1,l,mid),query_ma(i<<1|1,mid+1,r));
	}
}t1,t2;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
	t1.build(1,1,n,0),t2.build(1,1,n,1);
	for (int i=1; i<=n; i++) if (!v[i].empty())
	{
		for (int j=0,sz=v[i].size(); j<sz; j++)
		{
			int nw=t1.query_mi(1,v[i][j],v[i][j])-min(t1.query_mi(1,1,v[i][j]-1),0)+t2.query_mi(1,v[i][j],v[i][j])-min(t2.query_mi(1,v[i][j]+1,n),0);
			ans[v[i][j]]=(nw-1>>1);
		}
		for (int j=0,sz=v[i].size(); j<sz; j++) t1.add(1,v[i][j],n,-2),t2.add(1,1,v[i][j],-2);		
		for (int j=0,sz=v[i].size(); j<sz; j++)
		{
			int nw=t1.query_mi(1,v[i][j],v[i][j])-max(t1.query_ma(1,1,v[i][j]-1),0)+t2.query_mi(1,v[i][j],v[i][j])-max(t2.query_ma(1,v[i][j]+1,n),0);
			ans[v[i][j]]=max(ans[v[i][j]],(-nw-1)-(-nw+1>>1));
		} 
	}
	for (int i=1; i<=n; i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}
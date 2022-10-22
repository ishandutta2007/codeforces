// By: Little09
// Problem: CF1614E Divan and a Cottage
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1614E
// Memory Limit: 1000 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,W=1e9+3e5,M=N*8*32;
const int mod=1e9+1;
namespace ST
{
	int tot=0;
	int lc[M],rc[M],a[M],b[M],t[M];
	inline int make_node(int l,int r)
	{
		++tot;
		lc[tot]=0,rc[tot]=0;
		a[tot]=l,b[tot]=r;
		return tot;
	}
	inline void push_down(int u,int l,int r)
	{
		int mid=l+r>>1;
		if (!lc[u]) lc[u]=make_node(l,mid);
		if (!rc[u]) rc[u]=make_node(mid+1,r);
		if (t[u]==0) return;
		a[lc[u]]+=t[u],b[lc[u]]+=t[u],t[lc[u]]+=t[u];
		a[rc[u]]+=t[u],b[rc[u]]+=t[u],t[rc[u]]+=t[u];
		t[u]=0;
	}
	inline void push_up(int u,int l,int r)
	{
		push_down(u,l,r);
		a[u]=a[lc[u]],b[u]=b[rc[u]];
	}
	void update(int &u,int L,int R,int l,int r,int k)
	{
		if (!u) u=make_node(L,R);
		if (L>R||l>r) return;
		if (l<=L&&R<=r) 
		{
			a[u]+=k,b[u]+=k,t[u]+=k;
			return;
		}
		int mid=L+R>>1;
		push_down(u,L,R);
		if (l<=mid) update(lc[u],L,mid,l,r,k);
		if (mid<r) update(rc[u],mid+1,R,l,r,k);
		push_up(u,L,R);
		return;
	}
	int query(int &u,int l,int r,int x,int tp)
	{
		//cout << l << " " << r << endl;
		if (!u) u=make_node(l,r);
		if (l==r) 
		{
			if (a[u]==x) return l;
			if (tp!=-1) return -1;
			return l;
		}
		int mid=l+r>>1;
		push_down(u,l,r);
		if (tp==-1)
		{
			if (b[lc[u]]>x) return query(lc[u],l,mid,x,tp);
			return query(rc[u],mid+1,r,x,tp);
		}
		//cout << lc[u] << endl;
		if (b[lc[u]]<x) return query(rc[u],mid+1,r,x,tp);
		if (a[rc[u]]>x) return query(lc[u],l,mid,x,tp);
		//cerr<<a[rc[u]]<<" "<<b[lc[u]]<<" " << x << endl;
		if (tp==1) return query(rc[u],mid+1,r,x,tp);
		return query(lc[u],l,mid,x,tp);
	}
	int ask(int &u,int l,int r,int x)
	{
		if (!u) u=make_node(l,r);
		if (l==r) return a[u];
		int mid=l+r>>1;
		push_down(u,l,r);
		if (x<=mid) return ask(lc[u],l,mid,x);
		return ask(rc[u],mid+1,r,x);
	}
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}

int main()
{
	int n=read(),p=1;
	ST::make_node(0,W);
	int lastans=0;
	for (int i=1;i<=n;i++)
	{
		int T=read();
		int l=ST::query(p,0,W,T,0),r=ST::query(p,0,W,T,1);
		//cout << T << " " << l << " " << r << endl;
		if (l==-1)
		{
			int u=ST::query(p,0,W,T,-1);
			//cout << u << endl;
			ST::update(p,0,W,0,u-1,1);
			ST::update(p,0,W,u,W,-1);
		}
		else
		{
			ST::update(p,0,W,0,l-1,1);
			ST::update(p,0,W,r+1,W,-1);
		}
		int k=read();
		while (k--)
		{
			int x=read();
			x=(x+lastans)%mod;
			printf("%d\n",lastans=ST::ask(p,0,W,x));
		}
	}
	return 0;
}
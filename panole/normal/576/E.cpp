#include<bits/stdc++.h>
using namespace std;

const int N=2000010;
int n,m,ex[N],ey[N],col[N],q,k,qe[N],qc[N],p[500010][51],po[500010];
vector<int> v[500010];

struct lct
{
	bool laz[N];
	int ch[N][2],fa[N],siz[N],val[N],sta[N],tp,tot;
	pair<int,int> mi[N];
	void upd(int x)
	{
		mi[x]=min(min(mi[ch[x][0]],mi[ch[x][1]]),make_pair(val[x],x));
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
	}
	int gnode(int v)
	{
		laz[++tot]=0;
		ch[tot][0]=ch[tot][1]=fa[tot]=0;
		mi[tot]=make_pair(v,tot),val[tot]=v,siz[tot]=1;
		return tot;
	}
	void pushdown(int x)
	{
		if (!laz[x]) return;
		swap(ch[x][0],ch[x][1]);
		if (ch[x][0]) laz[ch[x][0]]^=1;
		if (ch[x][1]) laz[ch[x][1]]^=1;
		laz[x]=0;
	}
	bool clc(int x) {return ch[fa[x]][1]==x;}
	bool is_root(int x) {return ch[fa[x]][clc(x)]!=x;}
	void rotate(int x)
	{
		int f=fa[x],g=fa[f],F=clc(x);
		if (!is_root(f)) ch[g][clc(f)]=x;
		fa[x]=g,fa[ch[f][F]=ch[x][F^1]]=f;
		fa[ch[x][F^1]=f]=x,upd(f);
	}
	void splay(int x)
	{
		int X=x;
		for (tp=0; !is_root(X); X=fa[X]) sta[++tp]=X;
		for (sta[++tp]=X; tp; tp--) pushdown(sta[tp]);
		for (int f=fa[x]; !is_root(x); rotate(x),f=fa[x])
			if (!is_root(f)) rotate(clc(x)==clc(f)?f:x);
		upd(x);
	}
	void access(int x)
	{
		int X=x;
		splay(x),ch[x][1]=0,upd(x);
		for (int f=fa[x]; f; f=fa[x])
			splay(f),ch[f][1]=x,upd(x=f);
		splay(X);
	}
	int findroot(int x)
	{
		access(x);
		for (pushdown(x); ch[x][0]; x=ch[x][0],pushdown(x));
		return splay(x),x;
	}
	void change(int x,int v) {val[x]=v,splay(x);}
	void makeroot(int x) {access(x),laz[x]^=1;}
	void link(int x,int y) {makeroot(x),fa[x]=y;}
	void cut(int x,int y) 
	{
		if (findroot(x)!=findroot(y)) return;
		makeroot(x),access(y),ch[y][0]=fa[x]=0,upd(y);
	}
	pair<pair<int,int>,int> query(int x,int y) {makeroot(x),access(y); return make_pair(mi[y],siz[y]);}
}t;

int main()
{
	t.mi[0]=make_pair(N,0),t.siz[0]=0;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1; i<=m; i++) scanf("%d%d",&ex[i],&ey[i]);
	for (int i=1; i<=q; i++) scanf("%d%d",&qe[i],&qc[i]),v[qe[i]].push_back(i);
	for (int i=1; i<=m; i++) v[i].push_back(N),t.gnode(v[i][0]),col[i]=0,po[i]=0;
	for (int i=1; i<=q; i++)
	{
		int x,y,X,Y;
		if (!p[ex[qe[i]]][qc[i]]) p[ex[qe[i]]][qc[i]]=t.gnode(N);
		if (!p[ey[qe[i]]][qc[i]]) p[ey[qe[i]]][qc[i]]=t.gnode(N);
		t.change(qe[i],v[qe[i]][++po[qe[i]]]),x=p[ex[qe[i]]][qc[i]],y=p[ey[qe[i]]][qc[i]];
		if (col[qe[i]]) X=p[ex[qe[i]]][col[qe[i]]],Y=p[ey[qe[i]]][col[qe[i]]];
		if (t.findroot(x)!=t.findroot(y))
		{
			if (col[qe[i]]) t.cut(X,qe[i]),t.cut(qe[i],Y);
			t.link(x,qe[i]),t.link(y,qe[i]),col[qe[i]]=qc[i];
			puts("YES");
		} else
		{
			if (col[qe[i]]==qc[i]) 
			{
				pair<pair<int,int>,int> nw=t.query(X,Y);
				if (nw.first.first<v[qe[i]][po[qe[i]]])
				{
					x=p[ex[nw.first.second]][col[nw.first.second]];
					y=p[ey[nw.first.second]][col[nw.first.second]];
					t.cut(x,nw.first.second),t.cut(y,nw.first.second);
					t.link(X,qe[i]),t.link(Y,qe[i]);
				}
				puts("YES"); 
				continue;
			}
			pair<pair<int,int>,int> nw=t.query(x,y);
			if ((nw.second>>1)&1)
			{
				if (col[qe[i]]) t.cut(X,qe[i]),t.cut(qe[i],Y);
				if (nw.first.first<v[qe[i]][po[qe[i]]])
				{
					X=p[ex[nw.first.second]][col[nw.first.second]];
					Y=p[ey[nw.first.second]][col[nw.first.second]];
					t.cut(X,nw.first.second),t.cut(Y,nw.first.second);
					t.link(x,qe[i]),t.link(y,qe[i]);
				}
				col[qe[i]]=qc[i],puts("YES");
			} else 
			{
				if (col[qe[i]])
				{
					nw=t.query(X,Y);
					if (nw.first.first<v[qe[i]][po[qe[i]]])
					{
						x=p[ex[nw.first.second]][col[nw.first.second]];
						y=p[ey[nw.first.second]][col[nw.first.second]];
						t.cut(x,nw.first.second),t.cut(y,nw.first.second);
						t.link(X,qe[i]),t.link(Y,qe[i]);
					}
				}
				puts("NO");
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,ans[300010],m,cnt,nw,p[300010];
struct node{int x,y,len,ord;}a[300010];
bool cmp(node a,node b) {return a.len<b.len;}

struct lct
{
	int tp,sta[400010];
	int ch[400010][2],ma[400010],val[400010],fa[400010],vir[400010],siz[400010];
	bool laz[400010];
	void pushdown(int x)
	{
		if (!laz[x]) return;
		swap(ch[x][0],ch[x][1]);
		if (ch[x][0]) laz[ch[x][0]]^=1;
		if (ch[x][1]) laz[ch[x][1]]^=1;
		laz[x]=0;
	}
	void upd(int x)
	{
		ma[x]=max(val[x],max(ma[ch[x][0]],ma[ch[x][1]]));
		siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+vir[x]+1;
	}
	bool clc(int x) {return ch[fa[x]][1]==x;}
	bool is_root(int x) {return ch[fa[x]][clc(x)]!=x;}
	void rotate(int x)
	{
		int f=fa[x],g=fa[f],F=clc(x);
		if (!is_root(f)) ch[g][clc(f)]=x;
		fa[x]=g,fa[f]=x,ch[f][F]=ch[x][F^1];
		fa[ch[x][F^1]]=f,ch[x][F^1]=f,upd(f);
	}
	void splay(int x)
	{
		int X=x; tp=0;
		while (!is_root(X)) sta[++tp]=X,X=fa[X];
		pushdown(X);
		for (int i=tp; i; i--) pushdown(sta[i]);
		for (int f=fa[x]; !is_root(x); rotate(x),f=fa[x])
			if (!is_root(f)) rotate(clc(f)==clc(x)?f:x);
		upd(x);
	}
	void access(int x)
	{
		int X=x;
		splay(x),vir[x]+=siz[ch[x][1]],ch[x][1]=0,upd(x);
		for (int f=fa[x]; f; f=fa[x])
			splay(f),vir[f]+=siz[ch[f][1]],vir[f]-=siz[x],ch[f][1]=x,upd(x=f);
		splay(X);
	}
	void makeroot(int x) {access(x),laz[x]^=1;}
	int calc(int x) {return (x+1>>1)&1;}
	void link(int x,int y) 
	{
		makeroot(x),access(y);
		cnt-=calc(siz[x]),cnt-=calc(siz[y]);
		ch[y][1]=x,fa[x]=y,upd(y),cnt+=calc(siz[y]);
	}
	void cut(int x,int y)
	{
		makeroot(x),access(y);
		cnt-=calc(siz[y]),ch[y][0]=0,fa[x]=0,upd(y);
		cnt+=calc(siz[x]),cnt+=calc(siz[y]);
	}
	int findmax(int x)
	{
		pushdown(x);
		if (val[x]==ma[x]) return x;
		return findmax(ch[x][ma[ch[x][1]]==ma[x]]);
	}
	int findmax(int x,int y)
	{
		makeroot(x),access(y);
		x=findmax(y),splay(x);
		return x;
	}
	int findroot(int x)
	{
		access(x);
		for (pushdown(x); ch[x][0]; x=ch[x][0],pushdown(x));
		return splay(x),x;
	}
}t;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len),a[i].ord=i;
	for (int i=1; i<=n+m; i++) t.siz[i]=1;
	sort(a+1,a+1+m,cmp),nw=0,cnt=n;
	for (int i=1; i<=m; i++) p[a[i].ord]=i;
	for (int i=1; i<=m; i++) t.val[i+n]=t.ma[i+n]=a[i].ord;
	for (int i=m; i; i--)
	{
		if (i!=m)
		{
			t.access(p[i+1]+n);
			if (t.siz[p[i+1]+n]!=1)
				cnt--,t.cut(p[i+1]+n,a[p[i+1]].x),t.cut(p[i+1]+n,a[p[i+1]].y);
		}
		while (nw<m&&cnt>0)
		{
			nw++;
			if (a[nw].ord>i) continue;
			if (t.findroot(a[nw].x)==t.findroot(a[nw].y))
			{
				int x=t.findmax(a[nw].x,a[nw].y);
				if (t.val[x]<a[nw].ord) continue;
				t.cut(x,a[x-n].x),t.cut(x,a[x-n].y);
				t.link(nw+n,a[nw].x),t.link(nw+n,a[nw].y);
			} else cnt++,t.link(nw+n,a[nw].x),t.link(nw+n,a[nw].y);
		}
		if (cnt>0) 
		{
			for (int j=1; j<=i; j++) ans[j]=-1;
			break;
		}
		ans[i]=a[nw].len;
	}
	for (int i=1; i<=m; i++) printf("%d\n",ans[i]);
	return 0;
}
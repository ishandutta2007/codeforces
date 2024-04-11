#include<bits/stdc++.h>
using namespace std;

int n,x,y,bel[250010],hd[250010],cnt;
vector<int> v[250010];

int ask(int x) {return bel[x]==x?x:bel[x]=ask(bel[x]);}

struct lct
{
	int fa[250010],ch[250010][2],sta[250010],tp;
	bool laz[250010];
	bool clc(int x) {return ch[fa[x]][1]==x;}
	bool is_root(int x) {return ch[fa[x]][clc(x)]!=x;}
	void pushdown(int x)
	{
		if (!laz[x]) return;
		swap(ch[x][0],ch[x][1]);
		if (ch[x][0]) laz[ch[x][0]]^=1;
		if (ch[x][1]) laz[ch[x][1]]^=1;
		laz[x]=0;
	}
	void rotate(int x)
	{
		int f=fa[x],g=fa[f],F=clc(x);
		if (!is_root(f)) ch[g][clc(f)]=x;
		fa[x]=g,fa[ch[f][F]=ch[x][F^1]]=f;
		fa[ch[x][F^1]=f]=x;
	}
	void splay(int x)
	{
		int X=x; tp=0;
		while (!is_root(X)) sta[++tp]=X,X=fa[X];
		pushdown(X);
		for (int i=tp; i; i--) pushdown(sta[i]);
		for (int f=fa[x]; !is_root(x); rotate(x),f=fa[x])
			if (!is_root(f)) rotate(clc(x)==clc(f)?f:x);
	}
	void access(int x)
	{
		int X=x;
		splay(x),ch[x][1]=0;
		for (int f=fa[x]; f; f=fa[x]) splay(f),ch[f][1]=x,x=f;
		splay(X);
	}
	void makeroot(int x) {access(x),laz[x]^=1;}
	void link(int x,int y) {access(x),makeroot(y),fa[y]=x;}
	void cut(int x,int y) {makeroot(x),access(y),ch[y][0]=fa[x]=0;}
	int find(int x,int y)
	{
		makeroot(y),access(x);
		int ans=x;
		for (pushdown(x); x; pushdown(x))
		{
			if (ask(x)==ask(y)) 
			{
				if (!ch[x][1]) {splay(x); break;}
				x=ch[x][1];
			}
			else
			{
				ans=x;
				if (!ch[x][0]) {splay(x); break;}
				x=ch[x][0];
			}
		}
		return ans;
	}
	int getfa(int x)
	{
		splay(x),x=ch[x][0];
		for (pushdown(x); ch[x][1]; pushdown(x=ch[x][1]));
		splay(x);
		return x;
	}
}t;

void dfs(int x,int fa)
{
	for (int i=0,sz=v[x].size(); i<sz; i++)
		if (v[x][i]!=fa) dfs(v[x][i],x);
	if (!fa) return;
	int y=t.find(fa,x),z=t.getfa(y);
	t.cut(y,z),t.link(x,fa),printf("%d %d %d %d\n",x,fa,y,z);
	bel[ask(fa)]=ask(x);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	for (int i=0; i<=n; i++) bel[i]=i,t.fa[i]=0,t.ch[i][0]=t.ch[i][1]=0,t.laz[i]=0;
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),t.link(x,y);
	printf("%d\n",n-1),dfs(1,0);
	return 0;
}
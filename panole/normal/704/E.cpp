#include<bits/stdc++.h>
using namespace std;

const double eps=(1e-9);

struct node{int ord,v; double tl,tr,s;};
bool cmp(node a,node b){return a.tl<b.tl;}

struct spaly
{
	int rt,ch[100010][2],n,fa[100010],v[100010];
	double e[100010],s[100010];
	void init(int N) 
	{
		n=N,rt=0;
		for (int i=1; i<=n; i++) fa[i]=0,ch[i][0]=ch[i][1]=0;
	}
	int clc(int x) {return ch[fa[x]][1]==x;}
	void rotate(int x)
	{
		int f=fa[x],g=fa[f],F=clc(x);
		if (f!=rt) ch[g][clc(f)]=x; else rt=x;
		fa[x]=g,fa[f]=x,ch[f][F]=ch[x][F^1];
		fa[ch[x][F^1]]=f,ch[x][F^1]=f;
	}
	void splay(int x,int y=0)
	{
		for (int f=fa[x]; f!=y; rotate(x),f=fa[x])
			if (fa[f]!=y) rotate(clc(f)==clc(x)?f:x);
	}
	double getans(int x,double t)
	{
		double ans=100000000,nw;
		if (!x) return ans;
		splay(x);
		if (ch[x][0])
		{
			int y=ch[x][0];
			while (ch[y][1]) y=ch[y][1];
			splay(y,x);
			if (fabs(s[y]+v[y]*t-s[x]-v[x]*t)<eps) return t;
			if (v[y]>v[x])
			{
				nw=(s[x]-s[y])/(v[y]-v[x]);
				if (nw-eps<e[x]&&nw-eps<e[y]) ans=min(ans,nw);
			}
		}
		if (ch[x][1])
		{
			int y=ch[x][1];
			while (ch[y][0]) y=ch[y][0];
			splay(y,x);
			if (fabs(s[y]+v[y]*t-s[x]-v[x]*t)<eps) return t;
			if (v[x]>v[y])
			{
				nw=(s[y]-s[x])/(v[x]-v[y]);
				if (nw-eps<e[x]&&nw-eps<e[y]) ans=min(ans,nw);
			}
		}
		return ans;
	}
	void ins(int x,int y,double t)
	{
		if (s[x]+v[x]*t<s[y]+v[y]*t) 
		{
			if (ch[x][1]) ins(ch[x][1],y,t);
			else ch[x][1]=y,fa[y]=x;
		} else
		{
			if (ch[x][0]) ins(ch[x][0],y,t);
			else ch[x][0]=y,fa[y]=x;
		}
	}
	double ins(int x,double S,int V,double T,double E)
	{
		s[x]=S,v[x]=V,e[x]=E;
		if (!rt) rt=x; else ins(rt,x,T),splay(x);
		return getans(x,T);
	}
	double erase(int x)
	{
		splay(x);
		if (ch[x][0])
		{
			int y=ch[x][0];
			while (ch[y][1]) y=ch[y][1];
			splay(y,x),rt=y,fa[y]=0;
			if (ch[x][1]) fa[ch[x][1]]=y;
			ch[y][1]=ch[x][1];
			return min(getans(ch[x][1],e[x]),getans(y,e[x]));
		}
		rt=ch[x][1],fa[ch[x][1]]=0;
		return getans(ch[x][1],e[x]);
	}
}t;

vector<node> v[100010];
int n,m,tp[100010],dfn[100010],cnt,hd[100010],x,y,dep[100010],T,V,fa[100010],siz[100010],num[100010];
struct edg{int to,next;}e[200010];
double tx,ty,ans;

void addedge(int x,int y)
{
	e[++cnt]=(edg){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(edg){x,hd[y]},hd[y]=cnt;
}

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1,siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	dfn[x]=(++cnt); int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (!ma) return;
	tp[maa]=tp[x],Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to);
}

int lca(int x,int y)
{
	if (dfn[x]<dfn[y]) swap(x,y);
	while (tp[x]!=tp[y])
	{
		x=fa[tp[x]];
		if (dfn[x]<dfn[y]) swap(x,y);
	}
	return y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y);
	fa[1]=0,dep[0]=0,dfs(1),tp[1]=1,cnt=0,Dfs(1);
	while (m--)
	{
		scanf("%d%d%d%d",&T,&V,&x,&y),tx=T,ty=T+(1.0*(dep[x]+dep[y]-2*dep[lca(x,y)]))/V;
		while (tp[x]!=tp[y])
		{
			if (dfn[x]<dfn[y])
			{
				num[tp[y]]++;
				v[tp[y]].push_back((node){num[tp[y]],V,ty-(1.0*(dfn[y]-dfn[tp[y]]+1))/V,ty,dfn[y]-ty*V});
				v[tp[y]].push_back((node){-num[tp[y]],0,ty,0.0,0.0});
				ty-=(1.0*(dfn[y]-dfn[tp[y]]+1))/V,y=fa[tp[y]];
			} else
			{
				num[tp[x]]++;
				v[tp[x]].push_back((node){num[tp[x]],-V,tx,tx+(1.0*(dfn[x]-dfn[tp[x]]+1))/V,dfn[x]+tx*V});
				v[tp[x]].push_back((node){-num[tp[x]],0,tx+(1.0*(dfn[x]-dfn[tp[x]]+1))/V,0.0,0.0});
				tx+=(1.0*(dfn[x]-dfn[tp[x]]+1))/V,x=fa[tp[x]];
			}
		}
		if (dfn[x]<dfn[y])
		{
			num[tp[x]]++;
			v[tp[x]].push_back((node){num[tp[x]],V,tx,ty,dfn[x]-tx*V});
			v[tp[x]].push_back((node){-num[tp[x]],0,ty,0.0,0.0});
		} else
		{
			num[tp[x]]++;
			v[tp[x]].push_back((node){num[tp[x]],-V,tx,ty,dfn[x]+tx*V});
			v[tp[x]].push_back((node){-num[tp[x]],0,ty,0.0,0.0});
		}
	}
	ans=1000000;
	for (int i=1; i<=n; i++) if (tp[i]==i)
	{
		for (int j=0,sz=v[i].size(); j<sz; j++)
			if (v[i][j].ord>0) v[i][j].tr+=eps;
			else v[i][j].tl+=eps;
		t.init(num[i]),sort(v[i].begin(),v[i].end(),cmp);
		double nw=1000000;
		for (int j=0,sz=v[i].size(); j<sz; j++)
		{
			if (nw<v[i][j].tl+eps) break;
			if (v[i][j].ord>0) nw=min(nw,t.ins(v[i][j].ord,v[i][j].s,v[i][j].v,v[i][j].tl,v[i][j].tr));
			else nw=min(nw,t.erase(-v[i][j].ord));
		}
		ans=min(ans,nw);
	}
	if (ans>900000) puts("-1"); else printf("%.10lf\n",ans);
	return 0;
}
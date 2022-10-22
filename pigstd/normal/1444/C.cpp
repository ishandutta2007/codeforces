#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=5e5+10;
int n,m,k,c[M],u[M],v[M],ans,p[M];
map<pii,int>t;int cnt,tot;
vector<pii>V[M];pii pp[M];

struct dsu
{
	int f[M<<1],sz[M<<1],top;
	pii p[M<<1];
	int find(int x){while(x!=f[x])x=f[x];return x;}
	void init(){for (int i=1;i<=2*n;i++)f[i]=i,sz[i]=1;}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y)return;
		if (sz[x]>sz[y])swap(x,y);
		f[x]=y,sz[y]+=sz[x],p[++top]=mp(x,y);
	}
	void clear(int k)
	{
		while(top>k)
		{
			auto x=p[top--];
			f[x.x]=x.x,sz[x.y]-=sz[x.x];
		}
	}
}T;

signed main()
{
	n=read(),m=read(),k=read();T.init();
	for (int i=1;i<=n;i++)c[i]=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		if (c[u[i]]==c[v[i]])
		{
			if (p[c[u[i]]])continue;
			if (T.find(u[i])!=T.find(v[i]))T.merge(u[i],v[i]+n),T.merge(u[i]+n,v[i]);
			else p[c[u[i]]]=1;
		}
		else
		{
			if (c[u[i]]>c[v[i]])swap(u[i],v[i]);
			if (!t[mp(c[u[i]],c[v[i]])])t[mp(c[u[i]],c[v[i]])]=++cnt,pp[cnt]=mp(c[u[i]],c[v[i]]);
			V[t[mp(c[u[i]],c[v[i]])]].pb(mp(u[i],v[i]));
		}
	}
	for (int i=1;i<=k;i++)
		if (!p[i])tot++;
	int ans=tot*(tot-1)/2-cnt;
	for (int i=1;i<=cnt;i++)
	{
		if (p[pp[i].x]||p[pp[i].y]){ans++;continue;}
		int bf=T.top,F=1;
		for (auto x:V[i])
		{
			if (T.find(x.x)==T.find(x.y)){F=0;break;}
			else T.merge(x.x,x.y+n),T.merge(x.y,x.x+n);
		}
		if (F)ans++;T.clear(bf);
	}
	cout<<ans<<'\n';
	return 0;
}
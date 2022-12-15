#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
    int getint()
    {
        char c;
        for (c=getchar();c<'0' || c>'9';c=getchar());
        int t=c-48;
        for (c=getchar();c>='0' && c<='9';c=getchar())
            t=t*10+c-48;
        return t;
    }
    int n,FA[300010],m,x,y,z,fa[300000],anc[300000][20],depth[300000];
    vector<pair<int,int> > a[300000];
    pair<pair<int,int>,pair<int,int> > e[2000000];
    bool b[2000000];
    LL mst,ANS[2000010],ans[2000000],cost[300000][20];
     
    int getf(int x)
    {
    	if (x==fa[x])
    		return x;
    	else
    	{
    		fa[x]=getf(fa[x]);
    		return fa[x];
    	}
    }
     
    void dfs(int x,int l)
    {
    	for (int i=0;i<a[x].size();i++)
    		if (l!=a[x][i].fi)
    		{
    			anc[a[x][i].fi][0]=x;
    			cost[a[x][i].fi][0]=a[x][i].se;
    			depth[a[x][i].fi]=depth[x]+1;
    			dfs(a[x][i].fi,x);
    		}
    }
     
    void init()
    {
    	for (int k=1;k<20;k++)
    		for (int i=1;i<=n;i++)
    		{
    			if (anc[i][k-1]==0)
    				continue;
    			anc[i][k]=anc[anc[i][k-1]][k-1];
    			cost[i][k]=max(cost[i][k-1],cost[anc[i][k-1]][k-1]);
    		}
    }
     
    LL get(int u,int v)
    {
    	if (depth[u]<depth[v])
    		swap(u,v);
    	LL t=0;
    	for (int k=19;k>=0;k--)
    	{
    		if (anc[u][k]==0)
    			continue;
    		if (depth[anc[u][k]]>=depth[v])
    		{
    			t=max(t,cost[u][k]);
    			u=anc[u][k];
    			if (depth[u]==depth[v])
    				break;
    		}
    	}
    	if (u==v)
    		return t;
    	for (int k=19;k>=0;k--)
    	{
    		if (anc[u][k]==0)
    			continue;
    		if (anc[u][k]!=anc[v][k])
    		{
    			t=max(t,max(cost[u][k],cost[v][k]));
    			u=anc[u][k];
    			v=anc[v][k];
    		}
    	}
    	return max(t,max(cost[u][0],cost[v][0]));
    }
     
    int lca(int x,int y){
    	if (depth[x]>depth[y]) swap(x,y);
    	FORD(i,19,0) if (depth[y]-(1<<i)>=depth[x]) y=anc[y][i];
    	if (x==y) return x;
    	FORD(i,19,0) if (anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    	return anc[x][0];
    }
    
    int GETFA(int x){
    	return FA[x]==x?x:FA[x]=GETFA(FA[x]);
    }
    void clm(int x,int d,int z){
    	x=GETFA(x);
    	while (depth[x]>d){
    		ANS[x]=z;
    		FA[x]=GETFA(anc[x][0]);
    		x=FA[x];
    	}
    }
    
    
    int main()
    {
    	scanf("%d%d",&n,&m);
    	FOR(i,1,n) ANS[i]=1000000000;
    	for (int i=1;i<=m;i++)
    	{
    		x=getint();
    		y=getint();
    		z=getint();
    		e[i]=mp(mp(z,i),mp(x,y));
    	}
    	sort(e+1,e+m+1);
    	for (int i=1;i<=n;i++)
    		fa[i]=i;
    		
    	FOR(i,1,n) FA[i]=i;
    	
    	for (int i=1;i<=m;i++)
    	{
    		x=getf(e[i].se.fi);
    		y=getf(e[i].se.se);
    		if (x==y) continue;
    		
    		mst+=e[i].fi.fi;
    		b[i]=true;
    		a[e[i].se.fi].pb(mp(e[i].se.se,e[i].fi.fi));
    		a[e[i].se.se].pb(mp(e[i].se.fi,e[i].fi.fi));
    		fa[x]=y;
    	}
    	depth[1]=1;
    	dfs(1,0);
    	init();
    	
    	FOR(i,1,m) if (!b[i]){
    		int l=lca(e[i].se.fi,e[i].se.se);
    		clm(e[i].se.fi,depth[l],e[i].fi.fi);
    		clm(e[i].se.se,depth[l],e[i].fi.fi);
    		
    		
    		}
    	
    	for (int i=1;i<=m;i++)
    	{
    		ans[e[i].fi.se]=mst;
    		if (b[i]){if (depth[e[i].se.fi]>depth[e[i].se.se]) ans[e[i].fi.se]=ANS[e[i].se.fi]; else ans[e[i].fi.se]=ANS[e[i].se.se];
    			continue;}
    		
    		ans[e[i].fi.se]=get(e[i].se.fi,e[i].se.se);
    	}
    	for (int i=1;i<=m;i++)
    		printf("%lld\n",ans[i]);
    	return 0;
    }
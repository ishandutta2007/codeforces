    #include<cstdio>
    #include<cstring>
    #include<iostream>
    #include<cstdlib>
    #include<string>
    #include<cmath>
    #include<algorithm>
    #include<vector>
    #include<set>
    #include<bitset>
    #include<map>
    #include<queue>
    #define pb push_back
    #define mp make_pair
    #define LL long long
    #define fi first
    #define se second
    using namespace std;
       
    int getint()
    {
        char c;
        for (c=getchar();c<'0' || c>'9';c=getchar());
        int t=c-48;
        for (c=getchar();c>='0' && c<='9';c=getchar())
            t=t*10+c-48;
        return t;
    }
       
    void putint(LL n)
    {
         char a[20];
         int size=0;
         if (n==0)
            putchar('0');
         while (n)
         {
               a[size++]=n%10+48;
               n/=10;
         }
         for (int i=size-1;i>=0;i--)
             putchar(a[i]);
         putchar('\n');
    }
     
    int n,m,x,y,z,fa[300000],anc[300000][20],depth[300000];
    vector<pair<int,int> > a[300000];
    pair<pair<int,int>,pair<int,int> > e[2000000];
    bool b[2000000];
    LL mst,ans[2000000],cost[300000][20];
     
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
     
    int main()
    {
    	scanf("%d%d",&n,&m);
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
    	for (int i=1;i<=m;i++)
    	{
    		x=getf(e[i].se.fi);
    		y=getf(e[i].se.se);
    		if (x==y)
    			continue;
    		mst+=e[i].fi.fi;
    		b[i]=true;
    		a[e[i].se.fi].pb(mp(e[i].se.se,e[i].fi.fi));
    		a[e[i].se.se].pb(mp(e[i].se.fi,e[i].fi.fi));
    		fa[x]=y;
    	}
    	depth[1]=1;
    	dfs(1,0);
    	init();
    	for (int i=1;i<=m;i++)
    	{
    		ans[e[i].fi.se]=mst;
    		if (b[i]){ans[e[i].fi.se]=-1;
    			continue;}
    		ans[e[i].fi.se]=get(e[i].se.fi,e[i].se.se);
    	}
    	for (int i=1;i<=m;i++)
    		if (ans[i]!=-1) printf("%lld\n",ans[i]);
    	return 0;
    }
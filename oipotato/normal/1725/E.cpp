#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=998244353;

typedef pair<int,int> pii;

int n;

vector<pii>g[N];

vector<int>fac[N],v[N];

int dfn[N],dis[N],dep[N];

bool cmp(int x, int y) {return dfn[x] < dfn[y];}

int top[N],son[N],siz[N],fa[N],dc;

void dfs(int x,int f)
{
    dfn[x]=++dc;
    siz[x]=1;
    for(auto [v,w]:g[x])
    {
        if(v==f)
            continue;
        dis[v]=dis[x]+1;
        dep[v]=dep[x]+1;
        dfs(v,x);
        siz[x]+=siz[v];
        if(siz[v]>siz[son[x]])
            son[x]=v;
    }
}

void dfs2(int x,int f)
{
    fa[x]=f;
    if(!son[x])
        return;
    top[son[x]]=top[x];
    dfs2(son[x],x);
    for(auto [v,w]:g[x])
    {
        if(v==f||v==son[x])
            continue;
        top[v]=v;
        dfs2(v,x);
    }
}

int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

void addedge(int x,int y,int z)
{
    g[x].push_back({y,z});
    g[y].push_back({x,z});
}

int a[N];

int sz[N];

long long ans=0;

int C(int x)
{
    return 1ll*x*(x-1)/2%P;
}

int fl[N];

vector<int>vs;

void getans(int x,int f,int ss)
{
    sz[x]=fl[x];
    fl[x]=0;
    vs.push_back(x);
    for(auto [v,w]:g[x])
    {
        if(v==f)
            continue;
        getans(v,x,ss);
        sz[x]+=sz[v];
        ans=(ans+1ll*C(sz[v])*(ss-sz[v])%P*w%P+1ll*C(ss-sz[v])*sz[v]%P*w%P)%P;
    }
}

void solve(vector<int>a) {
    for(auto x:a)
        fl[x]=1;
    int ss=a.size();
    int k = a.size();
	sort(a.begin(), a.begin() + k, cmp);
	int m = k;
	for (int j = 1; j < m; ++j)
		a.push_back(lca(a[j - 1], a[j])),k++;
	sort(a.begin(), a.begin() + k, cmp);
	k = unique(a.begin(), a.begin() + k) - a.begin();
    stack<int> stk;
	stk.push(a[0]);
	for (int j = 1; j < k; ++j) {
		int u = lca(stk.top(), a[j]);
		while (dep[stk.top()] > dep[u]) stk.pop();
		assert(stk.top() == u);
		stk.push(a[j]);
		addedge(u, a[j], dis[a[j]] - dis[u]);
	}
    getans(a[0],0,ss);
    for(auto x:vs)
        g[x].clear(),fl[x]=0;
    vs.clear();
}

int main()
{
    for(int i=2;i<=200000;i++)
    {
        if(!fac[i].size())
        {
            for(int j=i;j<=200000;j+=i)
                fac[j].push_back(i);
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for(auto x:fac[a[i]])
            v[x].push_back(i);
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back({v,0});
        g[v].push_back({u,0});
    }
    dfs(1,0);
    top[1]=1;
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        g[i].clear();
    for(int i=2;i<=200000;i++)
        if(v[i].size())
            solve(v[i]);
    printf("%lld\n",ans);
}
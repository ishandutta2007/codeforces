#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXM=200005;
set<pair<int,int> >edge[MAXN];
vector<int>cir[MAXN];
int vis[MAXM<<1],pre[MAXN],cnt;
ll cal(vector<int>t)
{
    int n=(int)t.size();
    ll res=0;
    for(int i=0;i<n;i++)
    {
        ll ax=t[i],ay=ax*ax;
        ll bx=t[(i+1)%n],by=bx*bx;
        res+=ax*by-ay*bx;
    }
    return res;
}
void dfs(int u,int la)
{
    pre[u]=la;
    while(!edge[u].empty())
    {
        auto nxt=edge[u].lower_bound(make_pair(la,0));
        if(nxt==edge[u].begin())nxt=--edge[u].end();
        else nxt--;
        if(vis[nxt->second])
        {
            int p=u;
            cnt++;
            do
            {
                cir[cnt].push_back(p);
                int q=pre[p];
                edge[q].erase(edge[q].lower_bound(make_pair(p,0)));
                p=q;
            }while(p!=u);
            reverse(cir[cnt].begin(),cir[cnt].end());
            if(cal(cir[cnt])<0)cir[cnt--].clear();
        }
        else
        {
            vis[nxt->second]=1;
            dfs(nxt->first,u);
        }
    }
}
vector<int>tmp[MAXN];
int id[MAXN];
map<pair<int,int>,int> mp;
vector<int>ed[MAXM],tree[MAXN];
int col[MAXN],dp[MAXN],mx[MAXN];
void dfs1(int u,int fa)
{
    dp[u]=1;
    for(int i=0;i<(int)tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==fa || col[v])continue;
        dfs1(v,u);
        dp[u]+=dp[v];
    }
}
void dfs2(int u,int fa,int rt,int &res)
{
    mx[u]=dp[rt]-dp[u];
    for(int i=0;i<(int)tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==fa || col[v])continue;
        dfs2(v,u,rt,res);
        mx[u]=max(mx[u],dp[v]);
    }
    if(2*mx[u]<=dp[rt])res=u;
}
int get_root(int u)
{
    dfs1(u,0);
    int rt=u;
    dfs2(u,0,u,rt);
    return rt;
}
void solve(int u,int dep)
{
    u=get_root(u);
    col[u]=dep;
    for(int i=0;i<(int)tree[u].size();i++)
    {
        int v=tree[u][i];
        if(!col[v])solve(v,dep+1);
    }
}
int main()
{
    int n,m,tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].insert(make_pair(b,tot++));
        edge[b].insert(make_pair(a,tot++));
    }
    for(int i=1;i<=n;i++)
    {
        edge[i].insert(make_pair(i%n+1,tot++));
        edge[i%n+1].insert(make_pair(i,tot++));
    }
    dfs(1,0);
    for(int i=1;i<=cnt;i++)
    {
        id[i]=i;
        tmp[i]=cir[i];
        sort(tmp[i].begin(),tmp[i].end(),greater<int>());
    }
    sort(id+1,id+cnt+1,[&](const int &a,const int &b){return tmp[a]<tmp[b];});
    for(int i=1;i<=cnt;i++)
    {
        int sz=(int)cir[i].size();
        for(int j=0;j<sz;j++)
        {
            int u=cir[i][j],v=cir[i][(j+1)%sz];
            if(u>v)swap(u,v);
            if(!mp[make_pair(u,v)])mp[make_pair(u,v)]=(int)mp.size();
            ed[mp[make_pair(u,v)]].push_back(i);
        }
    }
    for(int i=1;i<=(int)mp.size();i++)
        if((int)ed[i].size()==2)
        {
            int u=ed[i][0],v=ed[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    solve(1,1);
    for(int i=1;i<=cnt;i++)
        printf("%d ",col[id[i]]);
    return 0;
}
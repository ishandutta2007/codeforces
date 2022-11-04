#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int p[MAXN],loc[MAXN];
struct DSU
{
    int fa[MAXN];
    set<int> val[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
            val[i].insert(p[i]);
        }
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        fa[x]=y;
        if(val[x].size()>val[y].size())
            val[x].swap(val[y]);
        for(auto &t:val[x])
            val[y].insert(t);
        val[x].clear();
    }
    int query(int x,int y,int v)
    {
        x=find(x),y=find(y);
        if(val[x].size()>val[y].size())
            swap(x,y);
        int res=0;
        for(auto &t:val[x])
            res+=val[y].count(v-t);
        return res;
    }
}dsu;
bool vis[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]),loc[p[i]]=i;
    dsu.init(n);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[loc[i]-1] && vis[loc[i]+1])
            res+=dsu.query(loc[i]-1,loc[i]+1,i);
        if(vis[loc[i]-1])
            dsu.merge(loc[i]-1,loc[i]);
        if(vis[loc[i]+1])
            dsu.merge(loc[i],loc[i]+1);
        vis[loc[i]]=1;
    }
    printf("%d\n",res);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,m;

vector<int>g[N];

int u[N],v[N];

int fa[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int dfs(int x,int f,int tar)
{
    if(x==tar)
        return 1;
    for(auto v:g[x])
        if(v!=f)
        {
            if(dfs(v,x,tar))
                return 1;
        }
    return 0;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            g[i].clear(),fa[i]=i;
        set<int>s;
        int cc=0;
        vector<int>ans(m+1);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            if(find(u[i])==find(v[i]))
                ans[i]=1,s.insert(u[i]),s.insert(v[i]),cc++;
            else
                ans[i]=0,fa[find(u[i])]=find(v[i]),g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
        }
        if(cc==3&&s.size()==3)
        {
            auto x=*s.begin(),y=*s.rbegin();
            for(auto ss:g[x])
                if(dfs(ss,x,y))
                {
                    for(int i=1;i<=m;i++)
                    {
                        if((u[i]==x&&v[i]==ss)||(u[i]==ss&&v[i]==x))
                            ans[i]=1;
                        if((u[i]==x&&v[i]==y)||(v[i]==x&&u[i]==y))
                            ans[i]=0;
                    }
                    break;
                }
        }
        for(int i=1;i<=m;i++)
            printf("%d",ans[i]);
        puts("");
    }
}
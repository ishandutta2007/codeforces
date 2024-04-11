#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
vector<int> e[MAXN],sub[MAXN];
int l[MAXN],r[MAXN];
void dfs(int u,int f)
{
    int mx=0,tot=0;
    for(auto &v:e[u])
    {
        if(v==f)continue;
        dfs(v,u);
        tot+=sub[v].size();
        if(sub[mx].size()<sub[v].size())mx=v;
    }
    if(!mx)
    {
        sub[u].push_back(u);
        l[u]=1,r[u]=2;
        return;
    }
    int rig=2*tot+1,lef=2*sub[mx].size()-1;
    r[mx]=rig--,l[u]=rig;
    sub[u].swap(sub[mx]);
    for(auto &v:e[u])
    {
        if(v==f || v==mx)continue;
        for(auto &s:sub[v])
        {
            l[s]+=lef,r[s]+=lef;
            sub[u].push_back(s);
        }
        lef+=2*sub[v].size()-1;
        r[v]=rig--,l[u]=rig;
        sub[v].clear();
    }
    r[u]=2*tot+2;
    sub[u].push_back(u);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",l[i],r[i]);
    return 0;
}
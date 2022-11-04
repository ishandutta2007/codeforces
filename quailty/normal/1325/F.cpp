#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int MAXS=505;
int col[MAXN],mx;
vector<int> e[MAXN],st[MAXN];
void dfs(int u)
{
    vector<int> t;
    for(auto &v:e[u])
        if(col[v]>=0)
            t.push_back(col[v]);
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    col[u]=(int)t.size();
    for(int i=0;i<(int)t.size();i++)
        if(t[i]>i)
        {
            col[u]=i;
            break;
        }
    st[col[u]].push_back(u);
    mx=max(mx,col[u]);
    for(auto &v:e[u])
        if(col[v]<0)dfs(v);
}
int vis[MAXN],pre[MAXN];
void dfs2(int u)
{
    vis[u]=1;
    for(auto &v:e[u])
        if(!vis[v] && col[v]==col[u]-1)
            pre[v]=u,dfs2(v);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0;
    while(s*s<n)s++;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(col,-1,sizeof(col));
    dfs(1);
    for(int i=0;i<=mx;i++)
        if((int)st[i].size()>=s)
        {
            printf("1\n");
            for(int j=0;j<s;j++)
                printf("%d%c",st[i][j]," \n"[j==s-1]);
            return 0;
        }
    dfs2(st[s-1][0]);
    vector<int> cir;
    for(auto &v:e[st[s-1][0]])
        if(vis[v] && col[v]==0)
        {
            int t=v;
            while(t)
            {
                cir.push_back(t);
                t=pre[t];
            }
            break;
        }
    printf("2\n%d\n",s);
    for(int i=0;i<s;i++)
        printf("%d%c",cir[i]," \n"[i==s-1]);
    return 0;
}
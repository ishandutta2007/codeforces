#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN];
int in[MAXN],out[MAXN],p[MAXN],time_tag;
void dfs(int u)
{
    p[in[u]=++time_tag]=u;
    for(auto &v:e[u])dfs(v);
    out[u]=time_tag;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        e[p].push_back(i);
    }
    for(int i=1;i<=n;i++)
        sort(e[i].begin(),e[i].end());
    dfs(1);
    for(int i=1;i<=q;i++)
    {
        int u,k;
        scanf("%d%d",&u,&k);
        if(out[u]-in[u]+1<k)printf("-1\n");
        else printf("%d\n",p[in[u]+k-1]);
    }
    return 0;
}
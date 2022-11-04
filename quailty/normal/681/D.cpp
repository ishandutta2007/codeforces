#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int>e[MAXN],res;
int cnt[MAXN],out[MAXN];
bool key[MAXN];
void dfs(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        dfs(e[u][i]);
        cnt[u]+=cnt[e[u][i]];
    }
    if(key[u])
    {
        if(cnt[u])exit(0*printf("-1"));
        else res.push_back(u);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        e[p].push_back(q);
        out[q]++;
    }
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        key[a]=1;
        cnt[i]++;
        cnt[a]--;
    }
    for(int i=1;i<=n;i++)
        if(!out[i])dfs(i);
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d\n",res[i]);
    return 0;
}
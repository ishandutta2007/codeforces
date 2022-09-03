#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,a[maxn],use[maxn],cnt,ord[maxn];
vector<int> g[maxn],topo;
void dfs(int x)
{
    use[x]=1;
    for(int i=0;i<g[x].size();i++)
        if(use[g[x][i]]==1)
        {
            puts("-1");
            exit(0);
        }
        else if(!use[g[x][i]])
            dfs(g[x][i]);
    use[x]=2;
    topo.push_back(x);
}
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    scanf("%d%d",&n,&m);
    cnt=m;
    for(int i=1;i<=n;i++)
    {
        int cc=0;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",a+j);
            if(a[j]!=-1)
                ord[cc++]=j;
        }
        sort(ord,ord+cc,cmp);
        cnt++;
        for(int j=0;j<cc;j++)
        {
            if(j!=0&&a[ord[j]]!=a[ord[j-1]])
                cnt++;
            g[cnt].push_back(ord[j]);
            g[ord[j]].push_back(cnt+1);
        }
        cnt++;
    }
    for(int i=1;i<=cnt;i++)
        if(!use[i])
            dfs(i);
    for(int i=topo.size()-1;i>=0;i--)
        if(topo[i]<=m)
            printf("%d ",topo[i]);
    return 0;
}
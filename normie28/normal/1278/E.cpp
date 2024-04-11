#include <bits/stdc++.h>
using namespace std;
vector<int> gt[500001];
int n,m,i,j,k,t,t1,u,v,a,b;
int l[500001];
int r[500001];
void dfs(int x, int p)
{
    for (auto g : gt[x]) if (g-p)
    {
        t++;
        l[g]=t;
    }
    t++;
    r[x]=t;
    reverse(gt[x].begin(),gt[x].end());
    for (auto g : gt[x]) if (g-p)
    {
        dfs(g,x);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (i=1;i<n;i++)
    {
        cin>>u>>v;
        gt[u].push_back(v);
        gt[v].push_back(u);
    }
    l[1]=1;
    t=1;
    dfs(1,-1);
    for (i=1;i<=n;i++)
    {
        cout<<l[i]<<' '<<r[i]<<endl;
    }
}
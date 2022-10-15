#include <bits/stdc++.h>
using namespace std;
int n,m,i,j;
vector<int> gt[1001];
int col[1001],par[1001],dis[1001][1001],maxx[1001];
deque<int> deq;
void dfs(int x, int c)
{
    col[x]=c;
    for (int g : gt[x])
    {
        if (!col[g]) { par[g]=par[x]; dfs(g,3-c);}
        else if (col[g]+c!=3)
        {
            cout<<"-1";
            exit(0);
        }
    }
}
int main()
{
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        gt[u].push_back(v);
        gt[v].push_back(u);
    }
    for (i=1;i<=n;i++) if (!col[i])
    {
        par[i]=i;
        dfs(i,1);
    }
    for (i=1;i<=1000;i++)
    {
        for (j=1;j<=1000;j++)
        {
            dis[i][j]=1e9;
        }
        dis[i][i]=0;
        deq.push_back(i);
        while(deq.size())
        {
   //         cout<<deq.front()<<' ';
            for (int g : gt[deq.front()]) if (dis[i][g]==1e9)
            {
                dis[i][g]=dis[i][deq.front()]+1;
                deq.push_back(g);
            }
            deq.pop_front();
        }
    //    cout<<endl;
    }
    int res=0;
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (dis[i][j]!=1e9) {maxx[par[i]]=max(maxx[par[i]],dis[i][j]); }
    for (i=1;i<=n;i++) res+=maxx[i];
    cout<<res;
}
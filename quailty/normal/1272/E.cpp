#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
int a[MAXN],res[MAXN],dis[MAXN];
void bfs(int n,const vector<int> &src,const vector<int> &dst)
{
    for(int i=1;i<=n;i++)
        dis[i]=INF;
     queue<int> q;
     for(auto &u:src)
        q.push(u),dis[u]=0;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         for(const auto &v:e[u])
             if(dis[v]>dis[u]+1)
                q.push(v),dis[v]=dis[u]+1;
     }
     for(auto &u:dst)if(dis[u]<INF)
        res[u]=dis[u];
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int> odd,even;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]&1)odd.push_back(i);
        else even.push_back(i);
        if(i+a[i]<=n)e[i+a[i]].push_back(i);
        if(i-a[i]>=1)e[i-a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        res[i]=-1;
    bfs(n,odd,even);
    bfs(n,even,odd);
    for(int i=1;i<=n;i++)
        printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}
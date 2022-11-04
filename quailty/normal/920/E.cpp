#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
bool vis[MAXN],ban[MAXN];
list<int> fre;
vector<int> e[MAXN];
int bfs(int st)
{
    int res=0;
    queue<int> q;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1,res++;
        for(auto &v:e[u])ban[v]=1;
        for(auto itr=fre.begin();itr!=fre.end();)
        {
            int v=*itr;
            if(!ban[v])
            {
                q.push(v);
                fre.erase(itr++);
            }
            else itr++;
        }
        for(auto &v:e[u])ban[v]=0;
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fre.push_back(i);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> con;
    for(int i=1;i<=n;i++)
        if(!vis[i])con.push_back(bfs(i));
    sort(con.begin(),con.end());
    printf("%d\n",(int)con.size());
    for(int i=0;i<(int)con.size();i++)
        printf("%d%c",con[i]," \n"[i+1==(int)con.size()]);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=100005;
const int MAXE=500005;
vector<pair<int,int> >e[MAXN];
queue<int>q;
deque<int>ans;
int now[MAXN];
bool vis[MAXE];
void Euler(int u)
{
    while(now[u]+1<e[u].size())
    {
        now[u]++;
        if(vis[e[u][now[u]].second])continue;
        vis[e[u][now[u]].second]=1;
        Euler(e[u][now[u]].first);
        vis[e[u][now[u]].second]=0;
    }
    ans.push_back(u);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        e[a].push_back(make_pair(b,i));
        e[b].push_back(make_pair(a,i));
    }
    for(int i=1;i<=n;i++)
        if(e[i].size()&1)q.push(i);
    int cnt=m;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v;
        if(q.size()>=1)
        {
            v=q.front();
            q.pop();

        }
        else v=u;
        e[u].push_back(make_pair(v,++cnt));
        e[v].push_back(make_pair(u,cnt));
    }
    int st=0;
    for(int i=1;i<=n;i++)
    {
        if(e[i].size())
        {
            st=i;
            break;
        }
    }
    if(cnt&1)
    {
        e[st].push_back(make_pair(st,++cnt));
        e[st].push_back(make_pair(st,cnt));
    }
    memset(now,-1,sizeof(now));
    Euler(st);
    printf("%d\n",cnt);
    for(int i=1;i<ans.size();i++)
    {
        if(i&1)printf("%d %d\n",ans[i-1],ans[i]);
        else printf("%d %d\n",ans[i],ans[i-1]);
    }
    return 0;
}
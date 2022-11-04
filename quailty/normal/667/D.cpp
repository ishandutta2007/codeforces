#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
const int MAXN=3005;
const int MAXM=5005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,nxt;
}edge[MAXM];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
int dis[MAXN][MAXN];
void bfs(int st)
{
    memset(dis[st],INF,sizeof(dis[st]));
    dis[st][st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(dis[st][v]>dis[st][u]+1)
            {
                dis[st][v]=dis[st][u]+1;
                q.push(v);
            }
        }
    }
}
set<pair<int,int> >st;
vector<int>v[MAXN];
vector<int>rv[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    for(int i=1;i<=n;i++)
        bfs(i);
    for(int i=1;i<=n;i++)
    {
        st.clear();
        for(int j=1;j<=n;j++)
            if(dis[i][j]<INF)
            {
                st.insert(make_pair(dis[i][j],j));
                while((int)st.size()>3)st.erase(st.begin());
            }
        for(auto itr=st.begin();itr!=st.end();itr++)
            v[i].push_back(itr->second);
        st.clear();
        for(int j=1;j<=n;j++)
            if(dis[j][i]<INF)
            {
                st.insert(make_pair(dis[j][i],j));
                while((int)st.size()>3)st.erase(st.begin());
            }
        for(auto itr=st.begin();itr!=st.end();itr++)
            rv[i].push_back(itr->second);
    }
    int res[4],len=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j || dis[i][j]==INF)continue;
            for(int k=0;k<(int)rv[i].size();k++)
                for(int l=0;l<(int)v[j].size();l++)
                {
                    int t[4]={rv[i][k],i,j,v[j][l]};
                    bool isok=1;
                    for(int p=0;p<4;p++)
                        for(int q=p+1;q<4;q++)
                            if(t[p]==t[q])isok=0;
                    if(!isok)continue;
                    int tmp=0;
                    for(int p=1;p<4;p++)
                        tmp+=dis[t[p-1]][t[p]];
                    if(tmp>len)
                    {
                        len=tmp;
                        for(int p=0;p<4;p++)res[p]=t[p];
                    }
                }
        }
    for(int i=0;i<4;i++)
        printf("%d ",res[i]);
    return 0;
}
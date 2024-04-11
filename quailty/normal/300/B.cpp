#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=55;
const int MAXM=5555;
int d[MAXN];
struct Edge
{
    int to,next;
}edge[MAXM<<1];
int head[MAXN],tot;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
vector<int>lv;
vector<int>link[MAXN];
int cur;
bool vis[MAXN];
void dfs(int u,int fa)
{
    if(vis[u])return;
    vis[u]=1;
    link[cur].push_back(u);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)dfs(v,u);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
        d[u]++;
        d[v]++;
    }
    bool isok=1;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)lv.push_back(i);
        if(d[i]>2)isok=0;
    }
    if(isok)
    {
        for(int i=1;i<=n;i++)
            if(d[i]>=1 && !vis[i])
            {
                dfs(i,0);
                cur++;
            }
        bool flag=1;
        int cnt=0;
        for(int i=0;i<cur;i++)
        {
            if((int)link[i].size()>3)
                flag=0;
            else if((int)link[i].size()==2)
                cnt++;
        }
        if(flag && (int)lv.size()>=cnt)
        {
            int pot=0;
            for(int i=0;i<cur;i++)
            {
                if((int)link[i].size()==3)
                    printf("%d %d %d\n",link[i][0],link[i][1],link[i][2]);
                else if((int)link[i].size()==2)
                {
                    printf("%d %d ",link[i][0],link[i][1]);
                    printf("%d\n",lv[pot++]);
                }
            }
            for(int i=pot;i<(int)lv.size();i++)
            {
                printf("%d",lv[i]);
                if((i-pot)%3==2)printf("\n");
                else printf(" ");
            }
        }
        else printf("-1\n");
    }
    else printf("-1\n");
    return 0;
}
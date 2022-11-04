#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
vector<int>e[35];
ll rx[35],ry[35];
void dfs(int u,int fa,int dir,ll len)
{
    int now=(dir+3)%4;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        rx[v]=rx[u]+dx[now]*len;
        ry[v]=ry[u]+dy[now]*len;
        dfs(v,u,now,len>>1);
        now=(now+1)%4;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if((int)e[i].size()>4)return 0*printf("NO");
    dfs(1,0,0,1LL<<40);
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%lld %lld\n",rx[i],ry[i]);
    return 0;
}
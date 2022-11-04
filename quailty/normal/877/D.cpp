#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char str[MAXN][MAXN];
int dis[MAXN][MAXN][2];
void bfs(int sx,int sy,int n,int m,int k)
{
    memset(dis,INF,sizeof(dis));
    queue<tuple<int,int,int> > q;
    for(int d=0;d<2;d++)
    {
        dis[sx][sy][d]=0;
        q.push(make_tuple(sx,sy,d));
    }
    while(!q.empty())
    {
        tuple<int,int,int> t=q.front();
        q.pop();
        int x=get<0>(t),y=get<1>(t),c=get<2>(t);
        for(int i=0;i<4;i++)
            for(int j=1;j<=k;j++)
            {
                int tx=x+j*d[i][0],ty=y+j*d[i][1];
                if(tx>=1 && tx<=n && ty>=1 && ty<=m && str[tx][ty]=='.'
                && dis[tx][ty][i&1]>dis[x][y][c]+1)
                {
                    dis[tx][ty][i&1]=dis[x][y][c]+1;
                    q.push(make_tuple(tx,ty,i&1));
                }
                else break;
            }
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",str[i]+1);
    int sx,sy,ex,ey;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    bfs(sx,sy,n,m,k);
    int res=INF;
    for(int d=0;d<2;d++)
        res=min(res,dis[ex][ey][d]);
    printf("%d\n",(res<INF ? res : -1));
    return 0;
}
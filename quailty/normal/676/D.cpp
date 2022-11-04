#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1005;
const int DEP=4;
const int INF=0x3f3f3f3f;
const int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
char s[MAXN][MAXN];
bool c[MAXN][MAXN][DEP];
int dis[MAXN][MAXN][DEP];
void bfs(int sx,int sy,int n,int m)
{
    memset(dis,INF,sizeof(dis));
    queue<int>qx,qy,qd;
    dis[sx][sy][0]=0;
    qx.push(sx);
    qy.push(sy);
    qd.push(0);
    while(!qx.empty())
    {
        int ux=qx.front();
        int uy=qy.front();
        int ud=qd.front();
        qx.pop();
        qy.pop();
        qd.pop();
        if(dis[ux][uy][(ud+1)%4]>dis[ux][uy][ud]+1)
        {
            dis[ux][uy][(ud+1)%4]=dis[ux][uy][ud]+1;
            qx.push(ux);
            qy.push(uy);
            qd.push((ud+1)%4);
        }
        for(int i=0;i<4;i++)
        {
            int tx=ux+d[i][0];
            int ty=uy+d[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && c[ux][uy][(i+ud)%4] && c[tx][ty][(i+ud+2)%4])
                if(dis[tx][ty][ud]>dis[ux][uy][ud]+1)
                {
                    dis[tx][ty][ud]=dis[ux][uy][ud]+1;
                    qx.push(tx);
                    qy.push(ty);
                    qd.push(ud);
                }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char t=s[i][j];
            if(t=='+' || t=='-' || t=='>' || t=='U' || t=='L' || t=='D')c[i][j][0]=1;
            if(t=='+' || t=='|' || t=='^' || t=='R' || t=='L' || t=='D')c[i][j][1]=1;
            if(t=='+' || t=='-' || t=='<' || t=='R' || t=='U' || t=='D')c[i][j][2]=1;
            if(t=='+' || t=='|' || t=='v' || t=='R' || t=='U' || t=='L')c[i][j][3]=1;
        }
    int st[2],ed[2];
    for(int i=0;i<2;i++)
    {
        scanf("%d",&st[i]);
        st[i]--;
    }
    for(int i=0;i<2;i++)
    {
        scanf("%d",&ed[i]);
        ed[i]--;
    }
    bfs(st[0],st[1],n,m);
    int res=INF;
    for(int i=0;i<4;i++)
        res=min(res,dis[ed[0]][ed[1]][i]);
    printf("%d\n",(res<INF ? res : -1));
    return 0;
}
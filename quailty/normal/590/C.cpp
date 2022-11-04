#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1005;
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char s[MAXN][MAXN];
int dis[3][MAXN][MAXN];
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
};
void bfs(int n,int m,int k)
{
    queue<Point>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]==k+'1')
            {
                q.push(Point(i,j));
                dis[k][i][j]=0;
            }
    while(!q.empty())
    {
        Point u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=u.x+d[i][0];
            int ty=u.y+d[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && s[tx][ty]!='#')
                if(dis[k][tx][ty]>dis[k][u.x][u.y]+1)
                {
                    dis[k][tx][ty]=dis[k][u.x][u.y]+1;
                    q.push(Point(tx,ty));
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
    memset(dis,INF,sizeof(dis));
    for(int i=0;i<3;i++)bfs(n,m,i);
    int ans=INF;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int tot=0;
            for(int k=0;k<3;k++)
                tot=min(INF,tot+dis[k][i][j]);
            if(tot<INF)ans=min(ans,tot-2);
        }
    for(int nt=0;nt<3;nt++)
    {
        int t1=INF;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int tot=0;
                for(int k=0;k<3;k++)
                    if(k!=nt)
                       tot=min(INF,tot+dis[k][i][j]);
                if(tot<INF)t1=min(t1,tot-1);
            }
        if(t1==INF)continue;
        int t2=INF;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(s[i][j]!='1'+nt)continue;
                for(int k=0;k<3;k++)
                    if(k!=nt)
                       t2=min(t2,dis[k][i][j]);
            }
        if(t2==INF)continue;
        ans=min(ans,t1+t2-1);
    }
    printf("%d\n",(ans==INF ? -1 : ans));
    return 0;
}
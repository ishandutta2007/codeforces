#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[505][505];
int cnt[505][505];
int n,m;
int sx,sy,ex,ey;
bool judge(int tx,int ty)
{
    if(tx>0 && tx<=n && ty>0 && ty<=m)
        return 1;
    else return 0;
}
bool bfs()
{
    queue<int>qx,qy;
    qx.push(sx);
    qy.push(sy);
    cnt[sx][sy]=0;
    while(!qx.empty())
    {
        int px=qx.front();
        qx.pop();
        int py=qy.front();
        qy.pop();
        //printf("%d %d\n",px,py);
        for(int i=0;i<4;i++)
        {
            int tx=px+d[i][0];
            int ty=py+d[i][1];
            if(judge(tx,ty))
            {
                if(cnt[tx][ty]==0)
                {
                    if(tx==ex && ty==ey)return 1;
                }
                else
                {
                    qx.push(tx);
                    qy.push(ty);
                    cnt[tx][ty]--;
                }
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.')cnt[i+1][j+1]=1;
            else cnt[i+1][j+1]=0;
        }
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    if(bfs())printf("YES\n");
    else printf("NO\n");
    return 0;
}
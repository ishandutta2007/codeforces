#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
const char dir[]="DLRU";
char s[1005][1005],res[1000005];
int dis[1005][1005];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int sx,sy;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)
            if(s[i][j]=='X')sx=i,sy=j;
    }
    memset(dis,0x3f,sizeof(dis));
    queue<int>q;
    q.push(sx*m+sy);
    dis[sx][sy]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        int ux=t/m,uy=t%m;
        for(int i=0;i<4;i++)
        {
            int vx=ux+d[i][0],vy=uy+d[i][1];
            if(vx>=0 && vx<n && vy>=0 && vy<m
            && s[vx][vy]!='*' && dis[vx][vy]>dis[ux][uy]+1)
            {
                dis[vx][vy]=dis[ux][uy]+1;
                q.push(vx*m+vy);
            }
        }
    }
    for(int _=0;_<k;_++)
    {
        int nxt=-1;
        for(int i=0;i<4;i++)
        {
            int vx=sx+d[i][0],vy=sy+d[i][1];
            if(vx>=0 && vx<n && vy>=0 && vy<m && dis[vx][vy]<k-_)
            {
                nxt=i;
                break;
            }
        }
        if(nxt<0)return 0*printf("IMPOSSIBLE");
        sx+=d[nxt][0],sy+=d[nxt][1];
        res[_]=dir[nxt];
    }
    return 0*printf("%s",res);
}
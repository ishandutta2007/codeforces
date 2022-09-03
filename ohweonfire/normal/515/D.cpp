#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn=2005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const char fx[]={'<','>','^','v'};
const char fy[]={'>','<','v','^'};
char field[maxn][maxn];
int adj[maxn][maxn];
int n,m,cccccccccccc;
int qx[maxn*maxn],qy[maxn*maxn],front,rear;
inline void func(int &x,int &y)
{
    for(int k=0,nx,ny;k<4;k++)
    {
        nx=x+dx[k];
        ny=y+dy[k];
        if(nx&&ny&&nx<=n&&ny<=m&&field[nx][ny]=='.')
            adj[x][y]++;
    }
}
inline void fun(int &x,int &y)
{
    for(int k=0,nx,ny;k<4;k++)
    {
        nx=x+dx[k];
        ny=y+dy[k];
        if(nx&&ny&&nx<=n&&ny<=m&&field[nx][ny]=='.')
        {
            adj[nx][ny]--;
            if(adj[nx][ny]==1)
            {
                qx[rear]=nx;
                qy[rear++]=ny;
            }
        }
    }
}
void gao()
{
    while(front!=rear)
    {
        int x=qx[front],y=qy[front++];
        if(adj[x][y]==0)
            continue;
        for(int k=0,nx,ny;k<4;k++)
        {
            nx=x+dx[k];
            ny=y+dy[k];
            if(nx&&ny&&nx<=n&&ny<=m&&field[nx][ny]=='.')
            {
                field[x][y]=fx[k];
                field[nx][ny]=fy[k];
                fun(nx,ny);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(field[i][j]=='.')
            {
                puts("Not unique");
                return;
            }
    for(int i=1;i<=n;i++)
        printf("%s\n",field[i]+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",field[i]+1);
        for(int j=1;j<=m;j++)
            if(field[i][j]=='.')
                ++cccccccccccc;
    }
    if(cccccccccccc&1)
    {
        puts("Not unique");
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(field[i][j]=='.')
            {
                func(i,j);
                if(adj[i][j]==0){
                    puts("Not unique");
                    return 0;
                }
                if(adj[i][j]==1)
                {
                    qx[rear]=i;
                    qy[rear++]=j;
                }
            }
    gao();
    return 0;
}
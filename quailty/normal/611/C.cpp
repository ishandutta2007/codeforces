#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[505][505];
int a[505][505],pre[505][505];
int get(int u,int d,int l,int r)
{
    if(u>d || l>r)return 0;
    return pre[d][r]-pre[u-1][r]-pre[d][l-1]+pre[u-1][l-1];
}
bool check(int x,int y,int u,int d,int l,int r)
{
    return x>=u && x<=d && y>=l && y<=r;
}
int main()
{
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(s[i][j]=='#')continue;
            for(int k=0;k<4;k++)
            {
                int tx=i+d[k][0];
                int ty=j+d[k][1];
                if(s[tx][ty]=='.')a[i][j]++;
            }
        }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            pre[i][j]=pre[i][j-1]+a[i][j];
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            pre[i][j]+=pre[i-1][j];
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int r[2],c[2];
        scanf("%d%d%d%d",&r[0],&c[0],&r[1],&c[1]);
        int tot=get(r[0]+1,r[1]-1,c[0]+1,c[1]-1);
        if(r[0]==r[1])
        {
            for(int j=c[0];j<=c[1];j++)
            {
                if(s[r[0]][j]=='#')continue;
                for(int k=0;k<4;k++)
                {
                    int tx=r[0]+d[k][0];
                    int ty=j+d[k][1];
                    if(!check(tx,ty,r[0],r[1],c[0],c[1]))continue;
                    if(s[tx][ty]=='.')tot++;
                }
            }
        }
        else if(c[0]==c[1])
        {
            for(int i=r[0];i<=r[1];i++)
            {
                if(s[i][c[0]]=='#')continue;
                for(int k=0;k<4;k++)
                {
                    int tx=i+d[k][0];
                    int ty=c[0]+d[k][1];
                    if(!check(tx,ty,r[0],r[1],c[0],c[1]))continue;
                    if(s[tx][ty]=='.')tot++;
                }
            }
        }
        else
        {
            for(int j=c[0];j<=c[1];j++)
            {
                if(s[r[0]][j]=='#')continue;
                for(int k=0;k<4;k++)
                {
                    int tx=r[0]+d[k][0];
                    int ty=j+d[k][1];
                    if(!check(tx,ty,r[0],r[1],c[0],c[1]))continue;
                    if(s[tx][ty]=='.')tot++;
                }
            }
            for(int j=c[0];j<=c[1];j++)
            {
                if(s[r[1]][j]=='#')continue;
                for(int k=0;k<4;k++)
                {
                    int tx=r[1]+d[k][0];
                    int ty=j+d[k][1];
                    if(!check(tx,ty,r[0],r[1],c[0],c[1]))continue;
                    if(s[tx][ty]=='.')tot++;
                }
            }
            for(int i=r[0]+1;i<=r[1]-1;i++)
            {
                if(s[i][c[0]]=='#')continue;
                for(int k=0;k<4;k++)
                {
                    int tx=i+d[k][0];
                    int ty=c[0]+d[k][1];
                    if(!check(tx,ty,r[0],r[1],c[0],c[1]))continue;
                    if(s[tx][ty]=='.')tot++;
                }
            }
            for(int i=r[0]+1;i<=r[1]-1;i++)
            {
                if(s[i][c[1]]=='#')continue;
                for(int k=0;k<4;k++)
                {
                    int tx=i+d[k][0];
                    int ty=c[1]+d[k][1];
                    if(!check(tx,ty,r[0],r[1],c[0],c[1]))continue;
                    if(s[tx][ty]=='.')tot++;
                }
            }
        }
        printf("%d\n",tot/2);
    }
    return 0;
}
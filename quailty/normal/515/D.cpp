#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,c[2005][2005];
char s[2005][2005];
bool vis[2005][2005];
bool judge(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m && s[x][y]=='.';
}
queue<pair<int,int> >q;
void bfs(int x,int y)
{
    vis[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            int tx=p.first+d[k][0];
            int ty=p.second+d[k][1];
            if(judge(tx,ty) && !vis[tx][ty])
            {
                vis[tx][ty]=1;
                if(k==0)
                {
                    s[p.first][p.second]='<';
                    s[tx][ty]='>';
                }
                else if(k==1)
                {
                    s[p.first][p.second]='>';
                    s[tx][ty]='<';
                }
                if(k==2)
                {
                    s[p.first][p.second]='^';
                    s[tx][ty]='v';
                }
                if(k==3)
                {
                    s[p.first][p.second]='v';
                    s[tx][ty]='^';
                }
                for(int i=0;i<4;i++)
                {
                    int ttx=tx+d[i][0];
                    int tty=ty+d[i][1];
                    if(judge(ttx,tty) && !vis[ttx][tty])
                    {
                        c[ttx][tty]--;
                        if(c[ttx][tty]==1)
                        {
                            q.push(make_pair(ttx,tty));
                            vis[ttx][tty]=1;
                        }
                    }
                }
                break;
            }
        }
    }
}
bool has_ans()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='.')return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='*')continue;
            for(int k=0;k<4;k++)
                if(judge(i+d[k][0],j+d[k][1]))
                    c[i][j]++;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(c[i][j]==1 && !vis[i][j])bfs(i,j);
    if(has_ans())
        for(int i=0;i<n;i++)printf("%s\n",s[i]);
    else
        printf("Not unique\n");
    return 0;
}
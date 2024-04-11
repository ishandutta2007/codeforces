#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
char s[2005][2005];
bool vis[2005][2005];
bool judge(int x,int y)
{
    int cnt=0;
    for(int i=x;i<=x+1;i++)
    {
        for(int j=y;j<=y+1;j++)
        {
            cnt+=(s[i][j]=='*');
        }
    }
    return cnt==1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    queue<pair<int,int> >q;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(judge(i,j))
            {
                vis[i][j]=1;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0;i<=1;i++)
        {
            for(int j=0;j<=1;j++)
            {
                 s[p.first+i][p.second+j]='.';
            }
        }
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int tx=i+p.first;
                int ty=j+p.second;
                if(tx>=1 && tx<n && ty>=1 && ty<m)
                {
                    if(vis[tx][ty])continue;
                    else if(judge(tx,ty))
                    {
                        vis[tx][ty]=1;
                        q.push(make_pair(tx,ty));
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%s\n",s[i]+1);
    }
    return 0;
}
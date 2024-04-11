#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1005;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[MAXN][MAXN];
int tot,cnt[MAXN*MAXN],vis[MAXN][MAXN];
struct node
{
    int x,y;
    node(){}
    node(int _x,int _y):x(_x),y(_y){}
};
bool check(int x,int y,int n,int m)
{
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs(node st,int n,int m)
{
    queue<node>q;
    q.push(st);
    vis[st.x][st.y]=tot;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=u.x+d[i][0];
            int ty=u.y+d[i][1];
            if(check(tx,ty,n,m))
            {
                if(s[tx][ty]=='*')cnt[tot]++;
                else if(!vis[tx][ty])
                {
                    vis[tx][ty]=tot;
                    q.push(node(tx,ty));
                }
            }
        }
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='.' && !vis[i][j])
            {
                tot++;
                bfs(node(i,j),n,m);
            }
    while(k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        printf("%d\n",cnt[vis[x][y]]);
    }
    return 0;
}
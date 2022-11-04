#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=1005;
const int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char s[MAXN][MAXN];
char r[MAXN][MAXN];
int v[MAXN][MAXN],c[MAXN*MAXN],tot;
void dfs(int x,int y)
{
    v[x][y]=tot;
    c[tot]++;
    for(int i=0;i<4;i++)
    {
        int tx=x+d[i][0],ty=y+d[i][1];
        if(s[tx][ty]=='.' && !v[tx][ty])dfs(tx,ty);
    }
}
bool vis[MAXN*MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='.' && !v[i][j])
            {
                tot++;
                dfs(i,j);
            }
    stack<int>st;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='*')
            {
                int tot=1;
                for(int k=0;k<4;k++)
                {
                    int tx=i+d[k][0],ty=j+d[k][1];
                    if(s[tx][ty]=='.' && !vis[v[tx][ty]])
                    {
                        tot+=c[v[tx][ty]];
                        vis[v[tx][ty]]=1;
                        st.push(v[tx][ty]);
                    }
                }
                while(!st.empty())
                {
                    vis[st.top()]=0;
                    st.pop();
                }
                r[i][j]='0'+tot%10;
            }
            else r[i][j]='.';
        }
    for(int i=1;i<=n;i++)
        printf("%s\n",r[i]+1);
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=505;
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[MAXN][MAXN];
int c[MAXN][MAXN],cnt[MAXN*MAXN],tot;
void dfs(int x,int y)
{
    if(!s[x][y] || s[x][y]=='X' || c[x][y])return;
    cnt[c[x][y]=tot]++;
    for(int i=0;i<4;i++)
        dfs(x+d[i][0],y+d[i][1]);
}
void upd1(int x,int y,int k,int t)
{
    for(int i=x;i<=x+k-1;i++)
        for(int j=y;j<=y+k-1;j++)
            if(c[i][j])cnt[c[i][j]]+=t;
}
void upd2(int x,int y,int k,int t)
{
    for(int i=x;i<=x+k-1;i++)
        if(c[i][y])cnt[c[i][y]]+=t;
}
bool vis[MAXN*MAXN];
stack<int>st;
int cal(int x,int y,int k)
{
    int res=0;
    for(int i=x;i<=x+k-1;i++)
        if(!vis[c[i][y-1]])
        {
            st.push(c[i][y-1]);
            vis[c[i][y-1]]=1;
            res+=cnt[c[i][y-1]];
        }
    for(int i=x;i<=x+k-1;i++)
        if(!vis[c[i][y+k]])
        {
            st.push(c[i][y+k]);
            vis[c[i][y+k]]=1;
            res+=cnt[c[i][y+k]];
        }
    for(int j=y;j<=y+k-1;j++)
        if(!vis[c[x-1][j]])
        {
            st.push(c[x-1][j]);
            vis[c[x-1][j]]=1;
            res+=cnt[c[x-1][j]];
        }
    for(int j=y;j<=y+k-1;j++)
        if(!vis[c[x+k][j]])
        {
            st.push(c[x+k][j]);
            vis[c[x+k][j]]=1;
            res+=cnt[c[x+k][j]];
        }
    while(!st.empty())
    {
        vis[st.top()]=0;
        st.pop();
    }
    return res;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]=='.' && !c[i][j])
            {
                tot++;
                dfs(i,j);
            }
    int res=0;
    for(int i=1;i+k-1<=n;i++)
    {
        upd1(i,1,k,-1);
        res=max(res,cal(i,1,k));
        for(int j=2;j+k-1<=n;j++)
        {
            upd2(i,j-1,k,1);
            upd2(i,j+k-1,k,-1);
            res=max(res,cal(i,j,k));
        }
        upd1(i,n-k+1,k,1);
    }
    return 0*printf("%d\n",res+k*k);
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int a[110][110],n,m,k;
bool vis[30];
void co(int x1,int y1,int x2,int y2)
{
    rep(i,26)vis[i]=0;
    for(int i=0;i<4;i++)
    {
        int nx=x1+dx[i],ny=y1+dy[i];
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny])vis[a[nx][ny]]=1;
        nx=x2+dx[i];ny=y2+dy[i];
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny])vis[a[nx][ny]]=1;
    }
    int now=1;
    for(;vis[now];now++);
    a[x1][y1]=a[x2][y2]=now;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d%d",&n,&m,&k);
        rep(i,n)rep(j,m)a[i][j]=0;
        if(m&1)
        {
            if(k>(m-1)/2*n||(k&1))puts("NO");
            else
            {
                puts("YES");
                for(int i=1;i<=n;i+=2)co(i,1,i+1,1);
                for(int i=1;i<=n;i+=2)for(int j=2;j<=m;j+=2)
                if(k)co(i,j,i,j+1),co(i+1,j,i+1,j+1),k-=2;else co(i,j,i+1,j),co(i,j+1,i+1,j+1);
            }
        }
        else if(n&1)
        {
            if(k<m/2||(k&1)!=((m/2)&1))puts("NO");
            else
            {
                puts("YES");
                for(int i=1;i<=m;i+=2)co(1,i,1,i+1),k--;
                for(int i=2;i<=n;i+=2)for(int j=1;j<=m;j+=2)
                if(k)co(i,j,i,j+1),co(i+1,j,i+1,j+1),k-=2;else co(i,j,i+1,j),co(i,j+1,i+1,j+1);
            }
        }
        else
        {
            if(k&1)puts("NO");
            else
            {
                puts("YES");
                for(int i=1;i<=n;i+=2)for(int j=1;j<=m;j+=2)
                if(k)co(i,j,i,j+1),co(i+1,j,i+1,j+1),k-=2;else co(i,j,i+1,j),co(i,j+1,i+1,j+1);
            }
        }
        if(a[1][1])rep(i,n){rep(j,m)putchar(a[i][j]-1+'a');puts("");}
    }
    return 0;
}
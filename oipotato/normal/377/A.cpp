#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        char s[510][510];
        bool vis[510][510];
        rep(i,n)scanf("%s",s[i]+1);
        rep(i,n)rep(j,m)vis[i][j]=0;
        pair<int,int> q[510*510];
        int w=0;
        rep(i,n)if(!w)rep(j,m)if(s[i][j]=='.'){vis[i][j]=1;q[w=1]=mp(i,j);break;}
        rep(i,w)
        {
            int x=q[i].first,y=q[i].second;
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k],ny=y+dy[k];
                if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&!vis[nx][ny]&&s[nx][ny]=='.')q[++w]=mp(nx,ny),vis[nx][ny]=1;
            }
        }
        for(int i=w;i>w-k;i--)s[q[i].first][q[i].second]='X';
        rep(i,n)puts(s[i]+1);
    }
    return 0;
}
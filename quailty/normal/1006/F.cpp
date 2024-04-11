#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=25;
int n,m;
ll k,a[MAXN][MAXN],res;
map<ll,ll> mp[MAXN];
void dfs_pre(int x,int y,ll sum)
{
    if(x+y==(n+m+2)/2)
    {
        mp[x][sum]++;
        return;
    }
    if(x<n)dfs_pre(x+1,y,sum^a[x+1][y]);
    if(y<m)dfs_pre(x,y+1,sum^a[x][y+1]);
}
void dfs_suf(int x,int y,ll sum)
{
    if(x+y==(n+m+2)/2)
    {
        if(mp[x].find(sum^k^a[x][y])!=mp[x].end())
            res+=mp[x][sum^k^a[x][y]];
        return;
    }
    if(x>1)dfs_suf(x-1,y,sum^a[x-1][y]);
    if(y>1)dfs_suf(x,y-1,sum^a[x][y-1]);
}
int main()
{
    scanf("%d%d%lld",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    dfs_pre(1,1,a[1][1]);
    dfs_suf(n,m,a[n][m]);
    printf("%lld\n",res);
    return 0;
}
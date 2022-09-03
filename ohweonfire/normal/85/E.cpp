#include <bits/stdc++.h>
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
typedef long long LL;
const int maxn=5005;
const int mod=1000000007;
int n,x[maxn],y[maxn],l,r,mid,cnt;
LL res;
short dist[maxn][maxn];
bool col[maxn],use[maxn];
bool dfs(int x,bool color)
{
    if(use[x])
    {
        return col[x]==color;
    }
    col[x]=color;
    use[x]=true;
    for(int i=1;i<=n;i++)
        if(dist[x][i]>mid&&!dfs(i,!color))
            return false;
    return true;
}
bool check()
{
    cnt=0;
    memset(use,0,sizeof(use));
    for(int i=1;i<=n;i++)
        if(!use[i])
        {
            if(!dfs(i,0))
                return false;
            cnt++;
        }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dist[i][j]=dist[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
    l=-1;
    r=10000;
    while(l<r-1)
    {
        mid=l+r>>1;
        if(check())
            r=mid;
        else
            l=mid;
    }
    mid=r;
    check();
    res=1;
    while(cnt--)res=(res+res)%mod;
    printf("%d\n%I64d\n",r,res);
    return 0;
}
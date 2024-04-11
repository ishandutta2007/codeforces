#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
const ll INF=(1LL<<62)-1;
ll x[MAXN],p[MAXN],c[MAXN],id[MAXN];
ll pre[MAXN],dp[2][MAXN];
void solve(int n,int l,int r,int tl,int tr)
{
    if(l>r)return;
    int m=(l+r)/2,tm=tr;
    ll &res=dp[1][m];
    for(int i=tl;i<=tr && i<=m;i++)
    {
        if(m-i>c[id[n]])continue;
        ll tmp=dp[0][i]+pre[m]-pre[i];
        if(res>tmp)res=tmp,tm=i;
    }
    solve(n,l,m-1,tl,tm);
    solve(n,m+1,r,tm,tr);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    int sum=0;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld",&p[i],&c[i]),sum+=c[i],id[i]=i;
    if(sum<n)return 0*printf("-1");
    sort(x+1,x+n+1);
    sort(id+1,id+m+1,[](ll a,ll b){return p[a]<p[b];});
    for(int j=0;j<=n;j++)
        dp[1][j]=(j>0)*INF;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            dp[0][j]=dp[1][j],dp[1][j]=INF;
        for(int j=1;j<=n;j++)
            pre[j]=pre[j-1]+abs(p[id[i]]-x[j]);
        solve(i,0,n,0,n);
    }
    return 0*printf("%lld",dp[1][n]);
}
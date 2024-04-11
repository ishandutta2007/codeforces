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
const int MOD=1e9+7;
int C[110][110],n,k;
LL f[110];
vector<int>g[110];
int dfs(int p,int fa,int dep,int aim)
{
    if(dep==aim)return 1;
    int res=0;
    for(auto i:g[p])if(i!=fa)res+=dfs(i,p,dep+1,aim);
    return res;
}
int main()
{
    C[0][0]=1;
    rep(i,100)
    {
        C[i][0]=1;
        rep(j,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    int T;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&k);
        rep(i,n)g[i].clear();
        rep(i,n-1){int x,y;scanf("%d%d",&x,&y);g[x].pb(y);g[y].pb(x);}
        if(k==2){printf("%d\n",C[n][2]);continue;}
        LL ans=0;
        for(int i=2;i<=n;i+=2)
        rep(j,n)
        {
            f[0]=1;rep(p,k)f[p]=0;
            for(auto nxt:g[j])
            {
                int cnt=dfs(nxt,j,1,i/2);
                for(int p=k;p;p--)(f[p]+=cnt*f[p-1])%=MOD;
            }
            (ans+=f[k])%=MOD;
        }
        printf("%lld\n",ans%MOD);
    }
    return 0;
}
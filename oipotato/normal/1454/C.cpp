#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
vector<int>g[200010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)g[i].clear(),g[i].pb(0);
        rep(i,n){int x;scanf("%d",&x);g[x].pb(i);}
        rep(i,n)g[i].pb(n+1);
        int ans=n;
        rep(i,n)if(g[i].size()>2)
        {
            int tans=0,cnt=g[i].size();
            rep(j,cnt-1)tans+=g[i][j]>g[i][j-1]+1;
            ans=min(ans,tans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
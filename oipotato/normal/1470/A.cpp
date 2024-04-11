#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int k[300010],c[300010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m;scanf("%d%d",&n,&m);
        rep(i,n)scanf("%d",&k[i]);
        rep(i,m)scanf("%d",&c[i]);
        sort(k+1,k+n+1,greater<int>());
        int now=0;
        LL ans=0;
        rep(i,n)if(now<k[i])ans+=c[++now];else ans+=c[k[i]];
        printf("%lld\n",ans);
    }
    return 0;
}
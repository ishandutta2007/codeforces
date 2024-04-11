#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,m,vis[110];
        rep(i,100)vis[i]=0;
        scanf("%d%d",&n,&m);
        rep(i,n){int x;scanf("%d",&x);vis[x]=1;}
        int ans=0;
        rep(i,m){int x;scanf("%d",&x);if(vis[x])ans++;}
        printf("%d\n",ans);
    }
    return 0;
}
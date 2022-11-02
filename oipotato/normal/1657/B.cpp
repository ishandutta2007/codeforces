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
        int n,B,x,y;
        scanf("%d%d%d%d",&n,&B,&x,&y);
        int now=0;
        LL ans=0;
        rep(i,n)
        {
            if(now+x<=B)now+=x;else now-=y;
            ans+=now;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
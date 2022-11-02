#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
LL cal(int l,int r){return (LL)(l+r)*(r-l+1)/2;}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,r;scanf("%d%d",&n,&r);
        LL ans=cal(1,min(n-1,r));
        if(n-1<r)ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
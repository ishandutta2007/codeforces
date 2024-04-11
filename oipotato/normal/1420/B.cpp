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
        int c[30];for(int i=0;i<30;i++)c[i]=0;
        int n;scanf("%d",&n);
        rep(i,n)
        {
            int x;scanf("%d",&x);
            for(int j=29;j>=0;j--)if((x>>j)&1){c[j]++;break;}
        }
        LL ans=0;
        for(int i=0;i<30;i++)ans+=(LL)c[i]*(c[i]-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}
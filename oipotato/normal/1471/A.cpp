#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        LL ans1=0,ans2=0;
        rep(i,n)
        {
            int y;
            scanf("%d",&y);
            ans1+=y;ans2+=(y-1)/x+1;
        }
        ans1=(ans1-1)/x+1;
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
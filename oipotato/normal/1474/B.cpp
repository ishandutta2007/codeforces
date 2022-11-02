#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool notp[30010];
int main()
{
    for(int i=2;i<=30000;i++)
    {
        for(int j=2;1ll*j*i<=30000;j++)notp[j*i]=1;
    }
    int T;
    for(scanf("%d",&T);T--;)
    {
        int d;scanf("%d",&d);
        int x=d+1;
        for(;notp[x];x++);
        int y=x+d;
        for(;notp[y];y++);
        LL ans1=1ll*x*x*x,ans2=1ll*x*y;
        printf("%lld\n",min(ans1,ans2));
    }
    return 0;
}
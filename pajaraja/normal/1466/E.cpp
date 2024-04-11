#include <bits/stdc++.h>
#define MAXN 500007
#define MOD 1000000007
using namespace std;
long long a[MAXN],cnt[65];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        long long res=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<60;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) for(int j=0;j<60;j++) if((1LL<<j)&a[i]) cnt[j]++;
        for(int i=1;i<=n;i++)
        {
            long long sor=0,sand=0;
            for(int j=0;j<60;j++)
            {
                if((1LL<<j)&a[i]) {sor=(sor+(long long)n*((1LL<<j)%MOD))%MOD; sand=(sand+cnt[j]*((1LL<<j)%MOD))%MOD;}
                else sor=(sor+cnt[j]*((1LL<<j)%MOD))%MOD;
            }
            res=(res+sor*sand)%MOD;
        }
        printf("%lld\n",res);
    }
}
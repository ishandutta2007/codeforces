#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000000;
const int Mod=1000000007;
int pw[15],tw[MAXN+5],cnt[MAXN+5],tot[MAXN+5],sum[MAXN+5];
int main()
{
    for(int i=(pw[0]=1);i<15;i++)
        pw[i]=10*pw[i-1];
    for(int i=(tw[0]=1);i<MAXN;i++)
        tw[i]=2*tw[i-1]%Mod;
    int n;
    scanf("%d",&n);
    for(int i=1,a;i<=n;i++)
    {
        scanf("%d",&a);
        cnt[a]++;
        tot[a]=(tot[a]+a)%Mod;
        sum[a]=(sum[a]+1LL*a*a)%Mod;
    }
    for(int i=0;i<6;i++)
        for(int j=MAXN-1;j>=0;j--)
            if(j/pw[i]%10)
            {
                cnt[j-pw[i]]=(cnt[j-pw[i]]+cnt[j])%Mod;
                tot[j-pw[i]]=(tot[j-pw[i]]+tot[j])%Mod;
                sum[j-pw[i]]=(sum[j-pw[i]]+sum[j])%Mod;
            }
    for(int i=0;i<MAXN;i++)
    {
        int cur=(1LL*tot[i]*tot[i]%Mod-sum[i]+Mod)%Mod;
        int tmp=1LL*cur*(cnt[i]>=2 ? tw[cnt[i]-2] : 0)%Mod;
        tmp=(tmp+1LL*sum[i]*(cnt[i]>=1 ? tw[cnt[i]-1] : 0))%Mod;
        sum[i]=tmp;
    }
    for(int i=0;i<6;i++)
        for(int j=0;j<MAXN;j++)
            if(j/pw[i]%10)
                sum[j-pw[i]]=(sum[j-pw[i]]-sum[j]+Mod)%Mod;
    ll res=0;
    for(int i=0;i<MAXN;i++)
        res^=1LL*i*sum[i];
    printf("%lld\n",res);
    return 0;
}
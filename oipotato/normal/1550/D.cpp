#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=(int)1e9+7;
int fac[200010],inv[200010];
int mypow(int x,int n){int res=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)res=1ll*res*x%MOD;return res;}
int C(int n,int m){if(m<0||n<m)return 0;return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
int main()
{
    fac[0]=1;
    rep(i,200000)fac[i]=1ll*fac[i-1]*i%MOD;
    inv[200000]=mypow(fac[200000],MOD-2);
    for(int i=199999;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%MOD;
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        int ans=(LL)min(1-l,r-n)*C(n,n/2)*((n&1)+1)%MOD;
        for(int k=min(1-l,r-n)+1;k<=min(n-l,r-1);k++)
        {
            int R=min(n,r-k),L=max(1,l+k);
            ans=(ans+C(R-L+1,n/2-(L-1)))%MOD;
            if(n&1)ans=(ans+C(R-L+1,n/2+1-(L-1)))%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,P=998244353;

int T;

int n;

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1ll*ret*a%P;
        b>>=1;
        a=1ll*a*a%P;
    }
    return ret;
}

int fac[N],inv[N],facc[N];

void pre(int n)
{
    facc[0]=facc[1]=1;
    for(int i=2;i<=n;i++)
        facc[i]=1ll*facc[i-2]*i%P;
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1ll*fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=1ll*inv[i+1]*(i+1)%P;
}

int C(int n,int m)
{
    if(n<m||n<0||m<0)
        return 0;
    return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;
}

int main()
{
    scanf("%d",&T);
    pre(6e5);
    while(T--)
    {
        scanf("%d",&n);
        int ans=0;
        vector<int>dp(n+1),f(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]+1ll*dp[i-2]*(i-1)%P)%P;
        for(int i=0;i<=n;i++)
            if((n-i)%4==0)
            {
                int num=(n-i)/2;
                int coe=C(n-num,num);
                if(num)
                    coe=1ll*coe*facc[num-1]%P*qpow(2,num/2)%P;
                ans=(ans+1ll*coe%P*dp[i]%P)%P;
            }
        printf("%d\n",ans);
    }
}
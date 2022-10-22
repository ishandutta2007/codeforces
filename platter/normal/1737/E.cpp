#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const long long x2=5e8+4;
long long dp[1000001];

long long fastpow(long long a,long long b) {
    if (b==0) {
        return 1;
    }
    if (b%2==1) {
        return (fastpow(a,b-1)*a)%mod;
    }
    long long half=fastpow(a,b/2);
    return (half*half)%mod;
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        if (n==1) {
            printf("1\n");
            continue;
        }
        printf("0\n");
        dp[n]=1;
        for(int i=n-1;i>=0;i--) {
            long long val=(dp[i+1]*x2)%mod;
            if (2*i<=n) {
                long long mi=fastpow(x2,i)*dp[i*2];
                mi%=mod;
                val+=mod-mi;
                val%=mod;
            }
            if (2*i+1<=n) {
                long long mi=fastpow(x2,i+1)*dp[i*2+1];
                mi%=mod;
                val+=mod-mi;
                val%=mod;
            }
            val+=(dp[i+1]*x2)%mod;
            if ((i+1)*2>n&&i*2<=n) {
                val+=mod-fastpow(x2,n-i);
                val%=mod;
            }
            dp[i]=val;
            //printf(".%lld\n",dp[i]);
        }
        long long ret=0;
        for(int i=1;i<n-1;i++) {
            long long v1=fastpow(x2,i/2+1);
            if ((n+2)/2>i+1) {
                v1*=dp[i+1];
                v1%=mod;
            }
            ret+=v1;
            printf("%lld\n",v1);
        }
        //printf(".%lld\n",ret+fastpow(x2,(n-1)/2));
        printf("%lld\n",fastpow(x2,(n-1)/2));
    }
    return 0;
}
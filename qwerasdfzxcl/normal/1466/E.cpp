#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll x[500500];
ll a[500500];
int on[100];
ll mod=1e9+7;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i=0;i<100;i++) on[i]=0;
        for (int i=0;i<n;i++) scanf("%lld", x+i);
        for (int i=0;i<n;i++) a[i]=0;
        for (int p=0;p<62;p++){
            for (int i=0;i<n;i++){
                if (x[i]&(1LL<<p)) on[p]++;
            }
            //printf("%d %d\n", p, on[p]);
        }
        for (int i=0;i<n;i++){
            for (int p=0;p<62;p++){
                if (x[i]&(1LL<<p)) a[i]=(a[i]+((n*((1LL<<p)%mod)))%mod)%mod;
                else a[i]=(a[i]+((on[p]*((1LL<<p)%mod))%mod))%mod;
            }
            //printf("%d %lld\n", i, a[i]);
        }
        ll ans=0;
        for (int p=0;p<62;p++){
            ll tmp=0;
            for (int i=0;i<n;i++){
                if (x[i]&(1LL<<p)) tmp=(tmp+((on[p]*a[i])%mod))%mod;
            }
            ll tmp2=(1LL<<p)%mod;
            ans += (tmp*tmp2)%mod;
            ans %= mod;
            //printf("%d %lld %lld %lld\n", p, ans, tmp, tmp2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
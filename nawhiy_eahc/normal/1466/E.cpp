#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll x[500002];
int cnt[60];

ll toLL(){
    ll ans = 0;
    for(int i=0;i<60;i++){
        ll temp = (1LL << i)%mod;
        ans += (temp*cnt[i])%mod;
        ans %= mod;
    }

    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        ll sum = 0, ans = 0;
        for(int i=0;i<60;i++){
            cnt[i] = 0;
        }
        for(int i=1;i<=n;i++){
            scanf("%lld", &x[i]);
            sum += x[i];
            sum %= mod;
            for(int j=0;j<60;j++){
                if(x[i] & (1LL << j)) cnt[j]++;
            }
        }

        for(int i=1;i<=n;i++){
            ll temp = (sum + n * (x[i]%mod))%mod;
            ans += (temp*temp)%mod;
            ans %= mod;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<60;j++){
                if(x[i] & (1LL << j)) cnt[j] = n - cnt[j];
            }

            ll temp = toLL();
            ans -= (temp*temp)%mod;
            ans %= mod;

            for(int j=0;j<60;j++){
                if(x[i] & (1LL << j)) cnt[j] = n - cnt[j];
            }
        }

        ans *= 500000004;
        ans %= mod;
        ans *= 500000004;
        ans %= mod;

        if(ans < 0) ans += mod;

        printf("%lld\n", ans);

    }
}
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll dp[100002];
char lvl[100002];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ll n, p, k, x, y;
        scanf("%lld %lld %lld", &n, &p, &k);
        p--;
        scanf("%s", lvl);
        scanf("%lld %lld", &x, &y);
        for (int i=0;i<k;i++){
            if (p+i>=n) continue;
            dp[i]=i*y;
            ll j=0;
            while(p+i+k*j<n){
                if (lvl[p+i+k*j]=='0') {
                    dp[i] += x;
                }
                j++;
            }
        }
        for (int i=k;p+i<n;i++){
            dp[i]=dp[i-k]+k*y;
            if (lvl[p+i-k]=='0') dp[i] -= x;
        }
        //for (int i=0;p+i<=n;i++) printf("%lld ", dp[i]);
        //printf("\n");
        ll ans=98765432265432;
        for (int i=0;p+i<n;i++) ans=min(ans, dp[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
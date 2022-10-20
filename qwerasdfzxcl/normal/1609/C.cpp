#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool prime[1001000];
int a[200200];

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        if (a[i]==1) a[i] = 1;
        else if (prime[a[i]]) a[i] = 2;
        else a[i] = 0;
    }

    ll ans = 0;

    for (int i=0;i<n;i++) if (a[i]==2){
        int l = 0, r = 0;
        int cur = i - k;
        while(cur>=0){
            if (a[cur]!=1) break;
            l++;
            cur -= k;
        }

        cur = i+k;
        while(cur<n){
            if (a[cur]!=1) break;
            r++;
            cur += k;
        }

        ans += (ll)(l+1) * (r+1) - 1;
    }
    printf("%lld\n", ans);
}

int main(){
    fill(prime+2, prime+1001000, 1);
    for (int i=2;i<1001000;i++){
        if (!prime[i]) continue;
        for (int j=2;i*j<1001000;j++) prime[i*j] = 0;
    }

    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
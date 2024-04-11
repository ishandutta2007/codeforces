#include "bits/stdc++.h"
using namespace std;
int n, k, a[(int)2e5 + 10];
typedef long long ll;
int main() {
    cin >> n >> k;
    for (int i = 2; i <= n + 1; i++) {
        scanf("%d", &a[i]);
    }
    ll ans = 0;
    /*for (int i = 0; i < n; i++) {
        if (i) {
            ll now = a[i - 1] + a[i];
            if (now % k == 0) {
                ans += now / k;
                a[i - 1] = a[i] = 0;
            }
            else {
                ans += a[i - 1]
            }
        }
        else {
            if (a[i] % k == 0) {
                ans += a[i] / k;
                a[i] = 0;
            }
        }
    }
    if (now) {
        ans += now % k ? now / k + 1 : now / k;
    }*/
    ll now = 0;
    for (int i = n + 1; i >= 2; i--) {
        if (a[i] == 0) {
            continue;
        }
        now = a[i] + a[i - 1];
        //cout << now << endl;
        ans += now / k;
        now %= k;
        a[i] = 0;
        if (a[i - 1] >= now)
            a[i - 1] = now;
        else {
            ans++;
            a[i - 1] = 0;
        }
    }
    cout << ans << endl;
}
/*
3 3
1 1 1
*/
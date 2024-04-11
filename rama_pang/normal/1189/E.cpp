#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, p, k;
    cin >> n >> p >> k;
    // (ai^4 - kai = aj^4 - kaj)
    map<int, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = (((((1ll * x * x) % p) * ((1ll * x * x) % p)) % p) - ((1ll * k * x) % p)) % p;
        if (x < 0) {
            x += p;
        }
        ans += mp[x];
        mp[x]++;
    }

    cout << ans << "\n";
    return 0;
}
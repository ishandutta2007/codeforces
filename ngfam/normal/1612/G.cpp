#include <bits/stdc++.h>
#define long long long

using namespace std;

const int maxn = 1000005;
const int mod = 1e9 + 7;

int fact[maxn];
int fcount[maxn + maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    auto add = [&](int i, int val) -> void {
        fcount[i + maxn] += val;
    };

    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        add(-(x - 1), 1);
        add(-(x - 1) + (x - 1) * 2 + 2, -1);
    }   

    for(int i = 2; i < maxn + maxn; ++i) fcount[i] += fcount[i - 2];

    fact[0] = 1;
    for(int i = 1; i < maxn; ++i) fact[i] = 1ll * fact[i - 1] * i % mod;

    long ans = 0, way = 1, start = 1;
    for(int i = 0; i < maxn + maxn; ++i) {
        if (fcount[i] == 0) continue;
        int len = fcount[i];
        long sum = 1ll * len * (len + 1) / 2 + 1ll * (start - 1) * len;
        sum %= mod;

        // cout << (i - maxn) << " " << len << endl;
        ans += sum * (i - maxn) % mod;
        ans %= mod;
        start += len;
        way = way * fact[len] % mod;
    }

    cout << ans << " " << way << endl;

    return 0;
}
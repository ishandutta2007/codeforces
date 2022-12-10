//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

const LL Mod = 1000 * 1000 * 1000 + 7;

LL pow2(LL x) {
    return (1LL << x) % Mod;
}

int solve() {
    int n;
    cin >> n;
    LL a[n];
    LL cnt[60] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 60; j++)
            if ((a[i] >> j) & 1LL)
                cnt[j]++;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL le = 0, ri = 0;
        for (int j = 0; j < 60; j++)
            if ((a[i] >> j) & 1LL) {
                le = (le + cnt[j] * pow2(j)) % Mod;
                ri = (ri + n * pow2(j)) % Mod;
            }
            else
                ri = (ri + cnt[j] * pow2(j)) % Mod;
        ans = (ans + le * ri) % Mod;
    }
    cout << ans << '\n';
    return 0;
}
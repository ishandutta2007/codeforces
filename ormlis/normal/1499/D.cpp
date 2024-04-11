#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e7 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

int mp[maxN];
ll cnt[maxN];
vector<int> primes;
void init() {
    cnt[1] = 1;
    for(int i = 2; i < maxN; ++i) {
        if (mp[i] == 0) {
            mp[i] = i;
            primes.push_back(i);
            cnt[i] = 2;
        }
        for(auto &p : primes) {
            if (1ll * p * i > maxN || p > mp[i]) break;
            cnt[p * i] = cnt[i];
            if (p != mp[i]) cnt[p * i] *= 2;
            mp[p * i] = p;
        }
    }
}
const int K = 5e3;
void solve() {
    int c, d, x;
    cin >> c >> d >> x;
    ll ans = 0;
    for (int g = 1; g <= K; ++g) {
        if (g > x) break;
        if (x % g != 0) continue;
        int k = (x / g) + d;
        if (k % c != 0) continue;
        k /= c;
        ans += cnt[k];
    }
    // ck > d / c
    int l = d / c + 1;
    for (int k = l; k <= l + K; ++k) {
        ll w = 1ll * c * k - d;
        if (w > x) break;
        if (x / w <= K) break;
        if (x % w != 0) continue;
        ans += cnt[k];
    }
    cout << ans << '\n';
}

int main() {
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
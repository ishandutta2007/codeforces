#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);
const ll MOD = (ll) (1e9 + 7);

template<typename A, typename B> void mini(A& x, const B& y) {
    if (y < x) {
        x = y;
    }
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int n;
ll k;
vector<ll> a;
vector<ll> e;

bool test(int mask, int bit) {
    return mask & (1 << bit);
}

void run() {
    cin >> n >> k;
    a.resize(n);
    for (ll& x : a) {
        cin >> x;
    }
    e.resize(n);
    for (ll& x : e) {
        cin >> x;
    }
    ll g = 0;
    for (ll x : a) {
        g = gcd(g, x);
    }
    if (g == 1) {
        cout << "0\n";
        return;
    }
    vector<ll> just;
    vector<ll> primes;
    for (ll d = 2; d * d <= g; d++) {
        if (g % d != 0) {
            continue;
        }
        ll t = 1;
        while (g % d == 0) {
            t *= d;
            g /= d;
        }
        primes.push_back(t);
        just.push_back(t);
    }
    if (g > 1) {
        primes.push_back(g);
        just.push_back(g);
    }

    int m = (int) primes.size();
    auto check = [m] (int mask, const vector<ll>& p) {
        ll res = 1;
        for (int i = 0; i < m; i++) {
            if (test(mask, i)) {
                res *= p[i];
            }
        }
        return res <= k;
    };

    map<vector<ll>, vector<ll>> wow;
    for (int i = 0; i < n; i++) {
        vector<ll> cur(m);
        ll x = a[i];
        for (int j = 0; j < m; j++) {
            cur[j] = 1;
            while (x % just[j] == 0) {
                x /= just[j];
                cur[j] *= just[j];
            }
        }
        wow[cur].push_back(e[i]);
    }

    vector<bool> ok(1 << m);
    vector<vector<ll>> dp(1 << m, vector<ll>(m + 1, LINF));
    dp[0][0] = 0;

    for (auto& it : wow) {
        vector<ll>& costs = it.second;
        sort(costs.begin(), costs.end());
        while ((int) costs.size() > m) {
            costs.pop_back();
        }
        for (int mask = 0; mask < (1 << m); mask++) {
            ok[mask] = check(mask, it.first);
        }
        for (int c : costs) {
            for (int mask = (1 << m) - 1; mask > 0; mask--) {
                for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                    if (!ok[submask]) {
                        continue;
                    }
                    for (int cnt = 1; cnt <= m; cnt++) {
                        mini(dp[mask][cnt], dp[mask ^ submask][cnt - 1] + c);
                    }
                }
            }
        }
    }

    ll ans = LINF;
    for (int take = 1; take <= m; take++) {
        ll x = dp[(1 << m) - 1][take];
        if (x != LINF) {
            mini(ans, x * take);
        }
    }
    cout << (ans == LINF ? -1 : ans) << "\n";
}
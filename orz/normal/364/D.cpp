#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int MX = 1000 * 1000 + 7;
const ll INF = 1e12 + 12345;

ll a[MX];
int cnt[MX];

bool TL() {
    return 1.0 * clock() / CLOCKS_PER_SEC > 3.5;
}

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    mt19937 rng(228);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = (n + 1) / 2;

    ll ans = 1;
    while (!TL()) {
        ll x = a[rng() % n];
        vector<ll> divs;
        vector<ll> prs;
        {
            for (ll i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    divs.push_back(i);
                    if (x / i != i) {
                        divs.push_back(x / i);
                    }
                }
            }
            sort(divs.begin(), divs.end());
        }
        {
            ll xx = x;
            for (ll i = 2; i * i <= x; i++) {
                if (xx % i == 0) {
                    prs.push_back(i);
                    while (xx % i == 0) {
                        xx /= i;
                    }
                }
            }
            if (xx != 1) {
                prs.push_back(xx);
            }
        }
        map<ll, int> pos;
        int ds = divs.size();
        for (int i = 0; i < ds;  i++) {
            pos[divs[i]] = i;
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            ll cx = gcd(a[i], x);
            cnt[pos[cx]]++;
        }
        for (int i = ds - 1; i >= 0; i--) {
            for (int j = 1; j < (1 << prs.size()); j++) {
                ll x = divs[i];
                int bc = 0;
                for (int k = 0; k < (int)prs.size(); k++) {
                    if (j & (1 << k)) {
                        x *= prs[k];
                        bc ^= 1;
                        if (x >= INF) {
                            break;
                        }
                    }
                }
                if (x >= INF) {
                    continue;
                }
                auto it = pos.find(x);
                if (it == pos.end()) {
                    continue;
                }
                if (bc == 1) {
                    cnt[i] += cnt[it->second];
                } else {
                    cnt[i] -= cnt[it->second];
                }
            }
        }

        for (int i = 0; i < ds; i++) {
            if (cnt[i] >= m) {
                ans = max(ans, divs[i]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

void solve() {
    int m, k; cin >> m >> k;
    // (x + d + v * t) ^ 2 = x^2 + d^2 + (v*t)^2 + d * (2vt + 2x)
    // x^2 + 2 * v * t * x + (v * t)^2
    vector<ll> s1(k), s2(k);
    range(i, k) {
        range(_, m) {
            int x; cin >> x;
            s1[i] += x;
            s2[i] += 1ll * x * x;
        }
    }
    int p = -1;
    {
        map<ll, ll> cnt;
        for (int i = 1; i < k; ++i) cnt[s1[i] - s1[i - 1]]++;
        for(int i = 1; i < k; ++i) {
            if (cnt[s1[i] - s1[i - 1]] <= 2) {
                p = i;
                break;
            }
        }
    }
    int l = 0;
    int r = 2;
    if (p <= r) {
        l = p + 1;
        r = l + 2;
    }
    ll a, b, c;
    // a * 0 + b * 0 + c = c
    c = s2[l + 1];
    a = (s2[r] + s2[l] - c * 2) / 2;
    b = s2[r] - a - c;
    ll t = p - (l + 1);
    ll must = a * t * t + b * t + c;
    ll res = s2[p] - must;
    ll d = s1[p] - (s1[p - 1] + (s1[l + 1] - s1[l]));
    res -= d * d;
    res /= 2 * d;
    cout << p << ' ' << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
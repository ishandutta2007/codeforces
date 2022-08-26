#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

const int md = 1e9 + 7;

int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

const int maxN = 1e5 + 5;
int a[maxN];
vi divs[maxN];
int sm[maxN];
int sumg[maxN];
int cnt[maxN];
ll too[maxN];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < maxN; ++i) {
        for (int j = i; j < maxN; j += i) {
            divs[j].push_back(i);
        }
    }
    for(int i = 1; i < maxN; ++i) {
        sm[i] = add(i, sm[i]);
        for(int j = i * 2; j < maxN; j += i) {
            sm[j] = sub(sm[j], sm[i]);
        }
    }
    int ans = 0;
    for(int g = n; g >= 1; --g) {
        int cur = 0;
        for(int d = g; d <= n; d += g) {
            for(auto &div : divs[a[d]]) {
                cur = add(cur, mul(cnt[div], sm[div]));
                cnt[div]++;
            }
            cur = sub(cur, sumg[d]);
        }

        for(int d = g; d <= n; d += g) {
            for(auto &div : divs[a[d]]) {
                cnt[div]--;
            }
        }
        sumg[g] = cur;
        ans = add(ans, mul(2, mul(cur, g)));
        ans = add(ans, mul(a[g], g));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
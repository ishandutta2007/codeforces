#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int maxN = 1e6 + 10;
int mp[maxN];
vi primes;

void init()  {
    for(int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for(auto &p : primes) {
            if (i * p >= maxN || mp[i] < p) break;
            mp[p * i] = p;
        }
    }
}

void solve() {
    int n, e; cin >> n >> e;
    vi a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, e) {
        for(int j = 0; i + j * e < n; ++j) {
            int x = a[i + j * e];
            if (x == 1 || mp[x] != x) continue;
            int l = j - 1, r = j + 1;
            while(l >= 0 && a[i + l * e] == 1) l--;
            while(i + r * e < n && a[i + r * e] == 1) r++;
            ans += 1ll * (j - l) * (r - j);
            ans--;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    init();
    range(_, t) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
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

const int maxN = 2e6 + 100;
int cnt[maxN];
int T = 1;
int was[maxN];

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] += 1e6 + 5;
    vector<int> have;
    queue<int> q;
    T++;
    rep(i, n) {
        rep(j, n) {
            int x = abs(a[i] - a[j]);
            if (was[x] == T) continue;
            was[x] = T;
            q.push(x);
        }
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        int sz = have.size();
        have.push_back(v);
        rep(i, sz) {
            int g = __gcd(have[i], v);
            if (was[g] == T) continue;
            was[g] = T;
            q.push(g);
        }
    }
    have.push_back(maxN);
    sort(rall(have));
    for(auto &g : have) {
        bool ok = false;
        rep(i, n) {
            int t = a[i] % g;
            cnt[t]++;
            if (cnt[t] >= n / 2) ok = true;
        }
        rep(i, n) {
            int t = a[i] % g;
            cnt[t]--;
        }
        if (ok) {
            if (g == maxN) {
                cout << "-1\n";
            } else {
                cout << g << '\n';
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
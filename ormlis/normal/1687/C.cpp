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
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 2e5 + 20;
const int LG = 30;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vi l(m), r(m);
    rep(i, m) cin >> l[i] >> r[i];
    rep(i, m) l[i]--;
    vl c(n + 1);
    rep(i, n) {
        c[i + 1] = c[i] + a[i] - b[i];
    }
    vvi to(n + 1);
    vi ct(m, 2);
    rep(i, m) {
        to[l[i]].push_back(i);
        to[r[i]].push_back(i);
    }
    queue<int> q1, q2;
    set<int> alive;
    rep(i, n + 1) {
        if (c[i] == 0) {
            q1.push(i);
        } else {
            alive.insert(i);
        }
    }
    if (c[n] != 0) {
        cout << "NO\n";
        return;
    }
    while (!q1.empty() || !q2.empty()) {
        while (!q1.empty()) {
            int i = q1.front();
            q1.pop();
            for (auto &j : to[i]) {
                ct[j]--;
                if (!ct[j]) {
                    q2.push(j);
                }
            }
        }
        while (!q2.empty()) {
            int i = q2.front();
            q2.pop();
            int l1 = l[i];
            int r1 = r[i];
            while (!alive.empty()) {
                auto it = alive.lower_bound(l1);
                if (it == alive.end()) break;
                int j = *it;
                if (j > r1) break;
                q1.push(j);
                alive.erase(it);
                c[j] = 0;
            }
        }
    }
    rep(i, n + 1) {
        if (c[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

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

void solve() {
    int n; cin >> n;
    vector<int> have(n);
    vector<int> g(n);
    rep(i, n) {
        int x; cin >> x;
        if (x <= n) {
            if (!have[x - 1]) {
                have[x - 1] = 1;
                continue;
            }
        }
        int t = (x - 1) / 2;
        t--;
        t = min(t, n - 1);
        if (t >= 0) g[t]++;
    }
    for(int i = n - 2; i >= 0; --i) g[i] += g[i + 1];
    int ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        if (have[i]) continue;
        ans++;
        if (g[i] < ans) {
            cout << "-1\n";
            return;
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
    rep(_, t) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for(int i = (a); i < (b); ++i)
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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi in(n), out(n);
    rep(i, n) {
        for (int j = i + a[i]; j < n; j += a[i]) {
            if (a[j] < a[i]) continue;
            in[j].push_back(i);
            out[i].push_back(j);
        }
        for (int j = i - a[i]; j >= 0; j -= a[i]) {
            if (a[j] < a[i]) continue;
            in[j].push_back(i);
            out[i].push_back(j);
        }
    }
    queue<int> q;
    vector<int> win(n, -1);
    rep(i, n) {
        if (out[i].empty()) {
            win[i] = 0;
            q.push(i);
        }
    }
    vi cnt(n);
    rep(i, n) cnt[i] = out[i].size();
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (win[v] == 0) {
            each(u, in[v]) {
                if (win[u] == -1) {
                    win[u] = 1;
                    q.push(u);
                }
            }
        } else {
            each(u, in[v]) {
                if (win[u] != -1) continue;
                cnt[u]--;
                if (cnt[u] == 0) {
                    q.push(u);
                    win[u] = 0;
                }
            }
        }
    }
    rep(i, n) cout << (win[i] ? "A" : "B");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20-7) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
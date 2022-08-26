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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 605;
const int LG = 20;

void solve() {
    int n, k; ll x; cin >> n >> k >> x;
    string s; cin >> s;
    vector<int> b;
    for(auto &c : s) {
        if (c == 'a') {
            b.push_back(-1);
            continue;
        }
        if (b.empty() || b.back() == -1) b.push_back(1);
        b.back() += k;
    }
    n = b.size();
    vector<ll> cnt(n + 1);
    cnt[n] = 1;
    for(int i = n - 1; i >= 0; --i) {
        cnt[i] = cnt[i + 1];
        if (b[i] == -1) continue;
        if (cnt[i] >= INF / b[i]) {
            cnt[i] = INF;
        } else {
            cnt[i] *= b[i];
        }
    }
    for(int i = 1; i <= n; ++i) {
        if (b[i - 1] == -1) {
            cout << 'a';
            continue;
        }
        while(cnt[i] < x) {
            cout << 'b';
            x -= cnt[i];
        }
    }
    cout << '\n';
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
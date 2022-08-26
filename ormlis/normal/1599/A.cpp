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
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

void solve() {
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vi b = {a.back()};
    a.pop_back();
    str s; cin >> s;
    rep1(i, n) {
        if (s[i] != s[i - 1]) {
            b.push_back(a.back());
            a.pop_back();
        }
    }
    reverse(all(b));
    reverse(all(a));
    for(int i = 1; i < (int)b.size(); i += 2) b[i] *= -1;
    for(int i = 0; i < (int)a.size(); i += 2) a[i] *= -1;
    int was = 1;
    vi result;
    result.push_back(b[0]);
    rep1(i, n) {
        if (s[i] != s[i - 1]) {
            result.push_back(b[was++]);
        } else {
            result.push_back(a[i-was]);
        }
    }
    ar<char, 2> to = {'L', 'R'};
    if (s[0] == 'L') swap(to[0], to[1]);
    for(auto &x : result) cout << abs(x) << ' ' << to[x>0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
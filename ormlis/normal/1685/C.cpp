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
    int n;
    cin >> n;
    string s;
    cin >> s;
    n *= 2;
    vpi ans;
    auto check0 = [&]() {
        int bal = 0;
        bool ok = true;
        for (auto c : s) {
            if (c == '(') bal++;
            else bal--;
            ok &= (bal >= 0);
        }
        return ok;
    };
    if (check0()) {
        cout << "0\n";
        return;
    }
    auto check1 = [&]() {
        int bal = 0;
        pair<int, int> L = {0, 0};
        rep(i, n) {
            if (s[i] == '(') bal++;
            else bal--;
            if (bal < 0) break;
            L = max(L, {bal, i + 1});
        }
        bal = 0;
        pair<int, int> R = {0, n};
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') bal++;
            else bal--;
            if (bal < 0) break;
            R = max(R, {bal, i});
        }
        int l = L.second;
        int r = R.second;
        assert(l + 1 < r);
        reverse(s.begin() + l, s.begin() + r);
        if (check0()) {
            ans.emplace_back(l, r - 1);
            return true;
        }
        reverse(s.begin() + l, s.begin() + r);
        return false;
    };
    if (!check1()) {
        int bal = 0;
        pair<int, int> kek = {0, 0};
        rep(i, n) {
            if (s[i] == '(') bal++;
            else bal--;
            kek = max(kek, {bal, i + 1});
        }
        ans.push_back({0, kek.second - 1});
        reverse(s.begin(), s.begin() + kek.second);
        assert(check1());
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
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
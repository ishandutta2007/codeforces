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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &x : s) {
        if (x == 'A') cnt++;
    }
    if (cnt != a + c + d) {
        cout << "NO\n";
        return;
    }
    int n = s.size();
    int e = 0;
    int cf = 0;
    vi cc;
    vi dd;
    int df = 0;
    for (int l = 0, r = 0; l < n; l = r) {
        r = l + 1;
        while (r < n && s[r] != s[r - 1]) r++;
        if (r - l == 1) continue;
        if ((r - l) % 2) {
            e += (r - l) / 2;
        } else {
            if (s[l] == 'A') {
                cc.push_back((r - l) / 2);
                cf += (r - l) / 2;
            } else {
                dd.push_back((r - l) / 2);
                df += (r - l) / 2;
            }
        }
    }
    sort(all(cc));
    sort(all(dd));
    while(cf > c) {
        cf -= cc.back();
        e += cc.back() - 1;
        cc.pop_back();
    }
    while(df > d) {
        df -= dd.back();
        e += dd.back() - 1;
        dd.pop_back();
    }
    if (d - df + c - cf <= e) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
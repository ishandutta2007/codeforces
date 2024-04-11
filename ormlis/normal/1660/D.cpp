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
const int maxN = 4e5 + 10;
const int LG = 100;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    ar<int, 2> rans = {0, n};
    for (int i = 0, j = 0; i < n; i = j) {
        if (a[i] == 0) {
            j++;
            continue;
        }
        while (j < n && a[j] != 0) j++;
        ar<int, 2> cnt = {0, INFi};
        int cur = 0;
        int x = 0;
        for (int e = i; e < j; ++e) {
            if (abs(a[e]) == 2) cur++;
            if (a[e] < 0) x ^= 1;
        }
        if (cur <= ans) continue;
        if (x == 0) {
            ans = cur;
            rans = {i, n - j};
            continue;
        }
        int t2 = cur;
        for (int e = i; e < j; ++e) {
            if (abs(a[e]) == 2) t2--;
            if (t2 <= ans) break;
            if (a[e] < 0) {
                ans = t2;
                rans = {e + 1, n - j};
                break;
            }
        }
        t2 = cur;
        for (int e = j - 1; e >= i; --e) {
            if (abs(a[e]) == 2) t2--;
            if (t2 <= ans) break;
            if (a[e] < 0) {
                ans = t2;
                rans = {i, n - e};
                break;
            }
        }
    }
    cout << rans[0] << ' ' << rans[1] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
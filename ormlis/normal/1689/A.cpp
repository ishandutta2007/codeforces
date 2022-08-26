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
const int maxN = 5e6 + 30;
const int LG = 100;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0;
    string c;
    int last = 0;
    int cnt = 0;
    while (i < n && j < m) {
        if (cnt == k) {
            if (last == 0) c += b[j++];
            else c += a[i++];
            cnt = 1;
            last ^= 1;
            continue;
        }
        if (a[i] < b[j]) {
            c += a[i++];
            if (last != 0) cnt = 0;
            last = 0;
            cnt++;
        } else {
            if (last != 1) cnt = 0;
            last = 1;
            cnt++;
            c += b[j++];
        }
    }
    cout << c << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
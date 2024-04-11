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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;

void solve() {
    int n; cin >> n;
    auto ask = [&] (int l, int r) {
        cout << "? " << l << ' ' << r << endl;
        ll x; cin >> x;
        assert(x != -1);
        return x;
    };
    int l = 1;
    int r = n;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if (ask(1, mid) != 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int i = r - 1;
    ll all = ask(i, n);
    ll a = all - ask(i + 1, n);
    int j = i + a + 1;
    assert(j <= n);
    ll bb = ask(j, n);
    ll b = bb - ask(j + 1, n);
    int k = j + b;
    assert(k <= n);
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
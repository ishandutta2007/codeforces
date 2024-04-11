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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 1e3 + 5;
const int LG = 19;

void solve() {
    int n;
    int mask_or = 0, mask_and = 0;
    int mask_xor = 0;
    cin >> n;
    rep(i, n) {
        char op; cin >> op;
        int x; cin >> x;
        if (op == '|') {
            mask_and &= (~x);
            mask_xor &= (~x);
            mask_or |= x;
        } else if (op == '^') {
            int t = mask_and & x;
            int e = mask_or & x;
            mask_and ^= t^e;
            mask_or ^= t^e;
            mask_xor ^= x^t^e;
        } else {
            mask_and |= (1023^x);
            mask_xor &= x;
            mask_or &= x;
        }
    }
    cout << "3\n";
    cout << "| " << mask_or << '\n';
    cout << "^ " << mask_xor << '\n';
    cout << "& " << (1023^mask_and) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
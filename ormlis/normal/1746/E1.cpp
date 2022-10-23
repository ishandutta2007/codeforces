#include "bits/stdc++.h"


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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
const int LG = 20;
const int md = 1e9 + 7;

void solve() {
    vi can;
    auto ask = [&](int l, int r) {
        cout << "? " << r - l + 1 << ' ';
        for (int i = l; i <= r; ++i) cout << can[i] << ' ';
        cout << endl;
        string s;
        cin >> s;
        return s == "YES";
    };
    int n;
    cin >> n;
    rep(i, n) can.push_back(i + 1);
    while (can.size() >= 4) {
        int sz = can.size();
        int mid3 = (sz * 3) / 4;
        int mid2 = (sz * 2) / 4;
        int mid1 = (sz) / 4;
        assert(0 < mid1 && mid1 < mid2 && mid2 < mid3 && mid3 < sz);
        bool vl = ask(0, mid2 - 1);
        bool vr = ask(mid1, mid3 - 1);
        if (vl && vr) {
            can.resize(mid3);
        } else if (vl && !vr) {
            can.erase(can.begin() + mid2, can.begin() + mid3);
        } else if (vr && !vl) {
            can.erase(can.begin(), can.begin() + mid1);
        } else {
            can.erase(can.begin() + mid1, can.begin() + mid2);
        }
    }
    auto answer = [&](int x) {
        cout << "! " << x << endl;
        string s;
        cin >> s;
        return s == ":)";
    };
    if (can.size() == 1) {
        assert(answer(can[0]));
        return;
    }
    if (can.size() == 2) {
        if (answer(can[0])) return;
        assert(answer(can[1]));
        return;
    }
    rep(_, 7) {
        bool val = ask(0, 1);
        if (!val) {
            rotate(can.begin(), can.begin() + 1, can.end());
            continue;
        }
        if (ask(2, 2)) {
            if (answer(can[2])) return;
            if (ask(0, 0)) {
                assert(answer(can[0]));
            } else {
                assert(answer(can[1]));
            }
            return;
        }
        if (answer(can[0])) return;
        assert(answer(can[1]));
        return;
    }
    assert(0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}
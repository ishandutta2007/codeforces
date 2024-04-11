#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e6 + 10;


void solve() {
    vector<pair<vi, vi>> have;
    have.emplace_back();
    int n; cin >> n;
    rep(i, n) {
        int x; cin >> x;
        have.back().first.push_back(x);
    }
    rep(i, n) {
        int x; cin >> x;
        have.back().second.push_back(x);
    }
    int res = 0;
    for(int b = 29; b >= 0; --b) {
        vector<pair<vi, vi>> nxt;
        bool ok = true;
        for(auto [A, B] : have) {
            vvi gA(2), gB(2);
            for(auto x : A) gA[(x>>b)&1].push_back(x);
            for(auto x : B) gB[(x>>b)&1].push_back(x);
            if (gA[0].size() != gB[1].size()) {
                ok = false;
                break;
            }
            if (!gA[0].empty()) nxt.emplace_back(gA[0], gB[1]);
            if (!gA[1].empty()) nxt.emplace_back(gA[1], gB[0]);
        }
        if (!ok) continue;
        res |= (1 << b);
        have = nxt;
    }
    cout << res << '\n';
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
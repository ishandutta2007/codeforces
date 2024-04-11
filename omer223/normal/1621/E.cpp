#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

template<class T>
struct rmq {
    vector<vector<T>> a;
    vector<int> logs;
    int dep, len;
    rmq(vector<T> arr) {
        len = arr.size();
        dep = 0;
        int tmp = len;
        while (tmp) {
            tmp >>= 1;
            dep++;
        }
        a.resize(dep);
        foru(i, 0, dep) {
            a[i].resize(len);
            for (int j = 0; j + (1 << i) <= len; j++) {
                if (!i)a[i][j] = arr[j];
                else a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
        initLogs();
    }
    void initLogs() {
        logs.resize(len + 1);
        logs[1] = 0;
        foru(i, 2, len + 1)logs[i] = logs[i >> 1] + 1;
    }
    T query(int l, int r) {
        if (l > r || r >= len)return 1;
        int mylen = logs[r - l + 1];
        return min(a[mylen][l], a[mylen][r - (1 << mylen) + 1]);
    }
};


inline bool can(ll a, pair<pll, int> s) {
    return (a * s.ff.ss >= s.ff.ff);
}

inline bool cmp(pair<pll, int> lhs, pair<pll, int> rhs) {
    ll lsm = lhs.ff.ff, lk = lhs.ff.ss, rsm = rhs.ff.ff, rk = rhs.ff.ss;
    ll lm = lsm * rk, rm = rsm * lk;
    return lm <= rm;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<vector<int>> s(m);
    vector<pair<pll, int>> smavg;
    foru(i, 0, n)cin >> a[i];
    sort(a.begin(), a.end());
    foru(i, 0, m) {
        int k;
        cin >> k;
        vector<int> tmp;
        ll sm = 0;
        foru(i, 0, k) {
            int x;
            cin >> x;
            tmp.push_back(x);
            sm += x;
        }
        s[i] = tmp;
        smavg.push_back({ { sm,k },i });
    }
    sort(smavg.begin(), smavg.end(), [](const pair<pll, int> lhs, const pair<pll, int> rhs) -> bool {
        ll lsm = lhs.ff.ff, lk = lhs.ff.ss, rsm = rhs.ff.ff, rk = rhs.ff.ss;
        ll lm = lsm * rk, rm = rsm * lk;
        if (lm != rm)return lm < rm;
        else return lsm < rsm;
    });
    int pos = n - 1;
    vector<int> canreg(m, 0), can1d(m, 0), can1u(m, 0);
    ford(i, m - 1, 0) {
        canreg[i] = can(a[pos], smavg[i]);
        if (i)can1d[i] = can(a[pos - 1], smavg[i]);
        if (i != m - 1)can1u[i] = can(a[pos + 1], smavg[i]);
        pos--;
    }
    rmq<int> rreg(canreg), r1d(can1d), r1u(can1u);
    vector<vector<int>> ans(m);
    foru(i, 0, m) {
        auto ii = smavg[i];
        for (int stval : s[ii.ss]) {
            auto jj = ii;
            jj.ff.ff -= stval;
            jj.ff.ss--;
            ll l = 1, r = m, bst = m, mid;
            while (l <= r) {
                mid = (l + r + 1) / 2;
                if (cmp(jj, smavg[mid - 1])) {
                    bst = mid - 1;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            bool val = 1;
            if (bst == i || bst == i + 1) {
                val &= can(a[(n - 1 - (m - i - 1))], jj);
                val &= rreg.query(0, i - 1);
                val &= rreg.query(i + 1, m - 1);
            }
            else if (bst > i) {
                val &= can(a[n - 1 - (m - bst)], jj);
                val &= r1d.query(i + 1, bst - 1);
                val &= rreg.query(0, i - 1);
                val &= rreg.query(bst, m - 1);
            }
            else {
                val &= can(a[n - 1 - (m - bst - 1)], jj);
                val &= r1u.query(bst, i - 1);
                val &= rreg.query(0, bst - 1);
                val &= rreg.query(i + 1, m - 1);
            }
            ans[ii.ss].push_back(val);
        }
    }
    for (vector<int> v : ans) {
        for (int y : v)cout << y;
    }
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}
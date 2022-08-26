#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;
int cnt = 0;

int req(const vector<int> &l, const vector<int> &r) {
    if (l.empty() || r.empty()) return 0;
    cout << "? " << l.size() << ' ' << r.size() << endl;
    for (auto &i : l) cout << i + 1 << ' ';
    cout << endl;
    for (auto &i : r) cout << i + 1 << ' ';
    cout << endl;
    int x;
    cin >> x;
    cnt--;
    assert(cnt >= 0);
    return x;
}

void solve() {
    int n;
    cin >> n;
    cnt = n + __lg(n);
    vector<int> l = {0};
    int R = -1, L = -1;
    int t = 0;
    for (int i = 1; i < n; ++i) {
        t = req(l, {i});
        if (t) {
            R = i;
            break;
        }
        l.push_back(i);
    }
    function<void(int, int)> check = [&](int le, int re) {
        if (le + 1 == re) {
            L = le;
            return;
        }
        int mid = (le + re) / 2;
        vector<int> lc;
        for (int i = le; i < mid; ++i) {
            lc.push_back(i);
        }
        if (req(lc, {R})) {
            check(le, mid);
        } else {
            check(mid, re);
        }
    };
    check(0, R);
    vector<int> ans;
    range(i, R) {
        if (i == L) continue;
        ans.push_back(i + 1);
    }
    for (int i = R + 1; i < n; ++i) {
        if (req({i, L}, {R}) == t) ans.push_back(i + 1);
    }
    sort(all(ans));
    assert(unique(all(ans)) == ans.end());
    cout << "! " << ans.size() << ' ';
    for (auto &i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
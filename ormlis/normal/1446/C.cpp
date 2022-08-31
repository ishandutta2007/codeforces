#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int get_solve(vector<int> &a) {
    int n = a.size();
    if (a.size() <= 2) return 0;
    vector<vector<int>> mxb(40);
    range(i, n) {
        int x;
        if (a[i] == 0) x = 0;
        else {
            x = 31 - __builtin_clz(a[i]);
            a[i] -= (1 << x);
            x++;
        }
        mxb[x].push_back(a[i]);
    }
    vector<int> pref(40);
    vector<int> suf(40);
    pref[0] = 0;
    range(e, 39) {
        pref[e + 1] = pref[e];
        if (mxb[e].empty()) continue;
        pref[e + 1] += (int) mxb[e].size();
    }
    for (int e = 37; e >= 0; --e) {
        suf[e] = suf[e + 1];
        if (mxb[e + 1].empty()) continue;
        suf[e] += (int) mxb[e + 1].size() - 1;
    }
    int ans = INFi;
    range(i, 40) {
        if (mxb[i].empty()) continue;
        ans = min(ans, max(0, pref[i] - 1) + suf[i] + get_solve(mxb[i]));
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    cout << get_solve(a) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
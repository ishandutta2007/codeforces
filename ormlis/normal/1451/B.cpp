#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref0(n), pref1(n);
    if (s[0] == '1') pref1[0]++;
    else pref0[0]++;
    range(i, n - 1) {
        pref0[i + 1] = pref0[i];
        pref1[i + 1] = pref1[i];
        if (s[i + 1] == '1') pref1[i + 1]++;
        else pref0[i + 1]++;
    }
    auto get0 = [&](int l, int r) {
        if (r < 0) return 0;
        int ans = pref0[min(n - 1, r)];
        if (l != 0) ans -= pref0[l - 1];
        return ans;
    };

    auto get1 = [&](int l, int r) {
        if (r < 0) return 0;
        int ans = pref1[min(n - 1, r)];
        if (l != 0) ans -= pref1[l - 1];
        return ans;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        bool bad = true;
        if (s[r] == '1') {
            if (get1(r + 1, n - 1)) bad = false;
        } else {
            if (get0(r + 1, n - 1)) bad = false;
        }

        if (s[l] == '1') {
            if (get1(0, l - 1)) bad = false;
        } else {
            if (get0(0, l - 1)) bad = false;
        }
        cout << (bad ? "NO\n" : "YES\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
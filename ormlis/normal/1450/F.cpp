#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> cnt(n);
    vector<pair<int, int>> can;
    a[0]--;
    cnt[a[0]]++;
    range(i, n - 1) {
        a[i + 1]--;
        if (a[i] == a[i + 1]) {
            cnt[a[i]] += 2;
        } else {
            can.emplace_back(a[i], a[i + 1]);
        }
    }
    cnt[a[n-1]]++;
    int s = accumulate(all(cnt), 0);
    int mx = max_element(all(cnt)) - cnt.begin();
    int tt = 0, tm = 0;
    for(auto &[i, j] : can) {
        if (i == mx || j ==mx) tm++;
        else tt++;
    }
    while(tt && (cnt[mx] - 1) * 2 > s) {
        s += 2;
        tt--;
    }
    if ((cnt[mx] - 1) * 2 <= s) {
        cout << s / 2 - 1 << "\n";
        return;
    }
    cout << "-1\n";
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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 9;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    range(i ,n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    range(i, n) {
        bool bad = false;
        if (i && a[i-1].first == a[i].first) bad= true;
        if (i + 1 != n && a[i+1].first == a[i].first) bad = true;
        if (!bad) {
            cout << a[i].second + 1 << "\n";
            return;
        }
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
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

void solve() {
    int n;
    ll W;
    cin >> n >> W;
    vector<pair<int, int>> a(n);
    range(i, n) cin >> a[i].first;
    range(i, n) a[i].second = i;
    sort(all(a));
    ll s = 0;
    range(i, n) {
        s += a[i].first;
        if (s <= W && s * 2 >= W) {
            cout << i + 1 << "\n";
            range(j, i + 1) cout << a[j].second + 1 << " ";
            cout << "\n";
            return;
        }
        if (a[i].first <= W && a[i].first * 2 >= W) {
            cout << "1\n";
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
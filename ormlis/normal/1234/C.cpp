#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char> (2));
    range(j, 2) range(i, n) cin >> a[i][j];
    int j = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i][j] > '2') {
            j ^= 1;
            if (a[i][j] <= '2') {
                cout << "NO\n";
                return;
            }
        }
    }
    if (j == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<vector<int>> p(n, vector<int> (n, 0));
    range(i, n) range(j, n) {
        char a; cin >> a;
        if (a == '1') p[i][j] = 1;
    }

    for(int i = n - 1; i >= 0; --i) {
        for(int j = n - 1; j >= 0; --j) {
            if (p[i][j]) {
                if (i == n - 1 || j == n - 1) continue;
                if (p[i+1][j] || p[i][j+1]) continue;
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
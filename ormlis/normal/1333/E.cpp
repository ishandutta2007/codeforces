#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> table(n, vector<int> (n));
    if (n <= 2) {
        cout << "-1\n";
        return;
    }
    if (n == 4) {
        cout << "4 3 6 12 \n"
                "7 5 9 15 \n"
                "14 1 11 10 \n"
                "13 8 16 2 \n";
        return;
    }
    if (n == 3) {
        cout << "1 2 7 \n"
                "6 8 3 \n"
                "5 9 4 \n";
        return;
    }
    int cur = 1;
    range(i, n - 3) {
        if ((n + i) & 1) range(j,n) table[i][j] = cur++;
        else for(int j = n - 1; j >= 0; --j) table[i][j] = cur++;
    }
    table[n-3][0] = cur++;
    table[n-2][0] = cur++;
    table[n-1][0] = cur++;
    for(int i = n - 1; i >= n - 3; --i) {
        if ((n - 1 - i) & 1) {
            for(int j = n - 4; j >= 1; --j) table[i][j] = cur++;
        } else {
            for(int j = 1; j <= n - 4; ++j) table[i][j] = cur++;
        }
    }
    table[n-3][n-3] = cur++;
    table[n-3][n-2] = cur++;
    table[n-2][n-1] = cur++;
    table[n-1][n-1] = cur++;
    table[n-1][n-3] = cur++;
    table[n-2][n-3] = cur++;
    table[n-3][n-1] = cur++;
    table[n-2][n-2] = cur++;
    table[n-1][n-2] = cur++;
    range(i, n) {
        range(j, n) cout << table[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
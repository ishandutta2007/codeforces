#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    vector<vector<char>> t(9, vector<char>(9));
    range(i, 9) range(j, 9) cin >> t[i][j];
    range(i, 9) {
        int r = i / 3;
        int j = i % 3;
        int cr = j * 3 + r;
        if (t[cr][i] == '9') {
            t[cr][i] = '1';
        } else {
            t[cr][i] = '9';
        }
    }
    range(i, 9) {
        range(j, 9) cout << t[i][j];
        cout << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
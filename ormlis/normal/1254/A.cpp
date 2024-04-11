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
int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<char>> t(r, vector<char>(c));
    range(i, r) range(j, c) cin >> t[i][j];

    int w = 0;
    range(i, r) range(j, c) w += (t[i][j] == 'R');

    string can = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    vector<vector<char>> ans(r, vector<char>(c, can[k - 1]));
    int i = 0, j = 0;
    int d = w % k;
    int e = w / k;
    range(s, d) {
        int cnt = e + 1;
        while (cnt) {
            if (j == c) j = c - 1, i++;
            if (j == -1) j = 0, i++;
            ans[i][j] = can[s];
            cnt -= (t[i][j] == 'R');
            j += -(i % 2) * 2 + 1;
        }
    }
    for (int s = d; s < k; ++s) {
        int cnt = e;
        while (cnt) {
            if (j == c) j = c - 1, i++;
            if (j == -1) j = 0, i++;
            ans[i][j] = can[s];
            cnt -= (t[i][j] == 'R');
            j += -(i % 2) * 2 + 1;
        }
    }
    range(f, r) {
        range(o, c) cout << ans[f][o];
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
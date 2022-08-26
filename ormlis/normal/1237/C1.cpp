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

vector<vector<int>> points;
int solve(int l, int r, int j) {
    if (j == 4) {
        return points[l][3];
    }
    int prev = -1;
    for(int i = l, e = l; i < r; i = e) {
        while(e < r && points[e][j] == points[i][j]) e++;
        auto k = solve(i, e, j + 1);
        if (k != -1) {
            if (prev == -1) prev = k;
            else {
                cout << prev << " " << k << "\n";
                prev = -1;
            }
        }
    }
    return prev;
}

void solve() {
    int n; cin >> n;
    points.resize(n, vector<int> (4));
    range(i, n) range(j, 3) cin >> points[i][j];
    range(i, n) points[i][3] = i + 1;
    sort(all(points));
    solve(0, n, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
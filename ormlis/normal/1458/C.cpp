#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 100 + 5;
const int md2 = 998244353;
const int md = 999999001;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    range(i, n) range(j, n) cin >> a[i][j];
    string C;
    cin >> C;
    vector<int> pos = {0, 1, 2};
    vector<int> add = {0, 0, 0};
    for (auto &c : C) {
        // i, j, z
        if (c == 'R') {
            add[1]++;
        } else if (c == 'L') {
            add[1]--;
        } else if (c == 'D') {
            add[0]++;
        } else if (c == 'U') {
            add[0]--;
        } else if (c == 'I') {
            swap(pos[1], pos[2]);
            swap(add[1], add[2]);
        } else {
            swap(pos[0], pos[2]);
            swap(add[0], add[2]);
        }
    }
    vector<vector<int>> b(n, vector<int> (n));
    range(i, n) {
        range(j, n) {
            ar<int, 3> kek = {i, j, a[i][j] - 1};
            ar<int, 3> res = {0, 0, 0};
            range(e, 3) {
                res[e] = (((kek[pos[e]] + add[e]) % n) + n) % n;
            }
            b[res[0]][res[1]] = res[2] + 1;
        }
    }
    range(i, n) {
        range(j, n) cout << b[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
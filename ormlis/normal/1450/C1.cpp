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
    vector<vector<int>> t(n, vector<int>(n));
    vector<vector<int>> p(n, vector<int>(n));

    int k = 0;
    vector<vector<pair<int, int>>> kek(3);
    range(i, n) {
        range(j, n) {
            char x;
            cin >> x;
            if (x == 'X') t[i][j] = 1;
            if (x == 'O') t[i][j] = 2;
            if (t[i][j]) {
                k++;
                kek[((i-j)%3+3)%3].emplace_back(i, j);
            }
        }
    }
    range(i, 3) {
        if (kek[i].size() * 3 <= k) {
            for(auto &[i2, j2] : kek[i]) {
                t[i2][j2] = 2;
            }
            break;
        }
    }

    range(i, n) {
        range(j, n) {
            if (t[i][j] == 0) cout << '.';
            if (t[i][j] == 1) cout << 'X';
            if (t[i][j] == 2) cout << 'O';
        }
        cout << "\n";
    }
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
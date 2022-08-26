#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 305;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    range(i, n) range(j, m) cin >> a[i][j];
    range(i, n) {
        range(j, m) {
            int cnt = 4;
            if (i == 0) cnt--;
            if (i == n - 1) cnt--;
            if (j == 0) cnt--;
            if (j == m - 1) cnt--;
            if (a[i][j] > cnt) {
                cout << "NO\n";
                return;
            }
            a[i][j] = cnt;
        }
    }
    cout << "YES\n";
    range(i, n) {
        range(j, m) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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
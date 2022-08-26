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
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m; cin >> n >> m;
    if (n < 2 || m < 2) {
        cout << "0\n";
        return;
    }
    if (n >= 4 && m >= 4) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> a(n, vector<int> (m));
    range(i, n) {
        range(j, m) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
    if (n < m) {
        vector<vector<int>> b(m, vector<int> (n));
        range(i, n) range(j, m) b[j][i] = a[i][j];
        swap(n, m);
        a = b;
    }
    vector<int> mask2 = {};
    if (m == 2) {
        mask2 = {1, 0};
    } else {
        mask2 = {5, 3, 0, 1};
    }
    int answer = INFi;
    range(mask, 1<<(m-1)) {
        int ans = 0;
        vector<vector<int>> tru = {{mask, mask ^ ((1<<m)-1)}, {mask2[mask], mask2[mask] ^ ((1<<m)-1)}};
        range(i, n) {
            int mn = 200;
            range(e, 2) {
                int cur = 0;
                range(j, m) {
                    int k = 0;
                    if ((tru[i&1][e] & (1<<j))) k =1;
                    if (k != a[i][j]) cur++;
                }
                mn = min(cur, mn);
            }
            ans += mn;
        }
        answer = min(answer, ans);
    }
    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
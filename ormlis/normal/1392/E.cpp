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
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll> (n, 0));
    vector<vector<ll>> mxp(n, vector<ll> (n, 0)), mnp(n, vector<ll> (n, 0));
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            ll mx = 0;
            range(e, i - 1) mx += a[e][0];
            range(e, j + 1) mx += a[i-1][e];
            ll mn = 0;
            range(e,i+1) mn += a[e][j-1];
            a[i][j-1] = max(0ll, mx - mn + 1);
        }
    }
    for(int i = 1; i < n; ++i) {
        range(j, n) {
            mnp[i][j] = a[i][j] + mnp[i-1][j];
            if (j != 0) mxp[i][j] = mxp[i][j-1] + a[i][j];
            else mxp[i][j] = mnp[i][j];
        }
    }
    range(i, n) {
        range(j, n) cout << a[i][j] << " ";
        cout << endl;
    }
    int q; cin >> q;
    while(q--) {
        ll k; cin >> k;
        vector<pair<int, int>> path;
        int i = n - 1, j = n -1;
        while(i != 0 || j != 0) {
            k -= a[i][j];
            path.emplace_back(i, j);
            if (j != 0 && k >= mnp[i][j-1]) {
                j--;
                continue;
            }
            i--;
        }
        path.emplace_back(i, j);
        reverse(all(path));
        for(auto &x: path) {
            cout << x.first + 1 << " " << x.second + 1 << endl;
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
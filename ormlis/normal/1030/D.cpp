#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <cmath>
#include <unordered_map>
#include <array>

#define ll long long
#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    if (1ll * n * m * 2 % k) {cout << "NO"; return;}
    ll s = 1ll * n * m * 2 / k;
    ll a = (s - 1) / m + 1;
    for(; a <= n; ++a) {
        if (s % a == 0) {
            ll b = s / a;
            if (a <= n && b <= m) {
                cout << "YES\n";
                cout << "0 0\n" << a << " 0\n" << "0 " << b;
                return;
            }
        }
        if (s / a == s / (a + 1)) break;
    }
    ll b = s / a;
    ll r = (s - 1) / n + 1;
    for(; b >= r; b--) {
        if (s % b == 0) {
            a = s / b;
            if (a <= n && b <= m) {
                cout << "YES\n";
                cout << "0 0\n" << a << " 0\n" << "0 " << b;
                return;
            }
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
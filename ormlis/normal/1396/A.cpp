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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    if (n == 1) {
        cout << "1 1\n" << -a[0] << "\n" << "1 1\n0\n1 1\n0\n";
        return;
    }
    vector<ll> b, c;
    range(i, n - 1) {
        // (a[i] % n) + b * n = c * (n - 1)
        ll ost = a[i] % (n - 1);
        if (ost < 0) ost += n - 1;
        b.push_back((n - 1 - ost) * n);
        a[i] += b.back();
        c.push_back(-a[i]);
    }
    b.push_back(0);
    cout << "1 " << n << "\n";
    range(i, n) cout << b[i] << " ";
    cout << "\n1 " << n - 1 << "\n";
    range(i, n - 1) cout << c[i] << " ";
    cout << "\n" << n << " " << n << "\n" << -a[n-1] << "\n";
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
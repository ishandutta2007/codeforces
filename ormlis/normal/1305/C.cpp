#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 80;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

int binpow(int a, int b, int m) {
    if (a < 0) a += m;
    if (b == 0) return 1;
    if (b % 2) return binpow(a, b - 1, m) * a % m;
    int mid = binpow(a, b / 2, m);
    return mid * mid % m;
}

void solve() {
    int n, m; cin >> n >> m;
    if (n > m) {cout << 0; return;}
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    vector<int> mode(m, 0);
    int ans = 1;
    range(i, n) {
        a[i] %= m;
        range(j, m) {
            ans = ans * binpow(a[i] - j, mode[j], m) % m;
        }
        mode[a[i]]++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}
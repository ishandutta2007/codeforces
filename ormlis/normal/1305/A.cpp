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

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    range(i, n) cout << a[i] << " ";
    cout << "\n";
    range(i, n) cout << b[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
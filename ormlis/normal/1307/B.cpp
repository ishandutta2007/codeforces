#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;

void solve() {
    int n, d; cin >> n >> d;
    int f = 0;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) {
        if (a[i] == d) {cout << "1\n"; return;}
        f = max(f, a[i]);
    }
    if (d % f == 0) {
        cout << d / f << "\n";
    } else {
        cout << max(d / f + 1, 2) << "\n";
    }
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
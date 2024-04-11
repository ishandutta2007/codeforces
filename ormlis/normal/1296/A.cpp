#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3 * 1e5 + 1;
ll md = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int c = 0, nc = 0;
    range(i, n) {
        if (a[i] % 2) nc = 1;
        else c = 1;
    }
    if (nc && (n % 2 || c)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
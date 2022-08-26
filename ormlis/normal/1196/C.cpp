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
const int maxN = 5001;
ll md = 1000000007;

void solve() {
    int n; cin >> n;
    int x1 = -1e5, y1 = -1e5, x2 = 1e5, y2 = 1e5;
    range(i, n) {
        int x, y; cin >> x >> y;
        int f1, f2, f3, f4; cin >> f1 >> f2 >> f3 >> f4;
        if (!f1) {
            x1 = max(x1, x);
        }
        if (!f2) {
            y2 = min(y2, y);
        }
        if (!f3) {
            x2 = min(x2, x);
        }
        if (!f4) {
            y1 = max(y1, y);
        }
    }
    if (x1 <= x2 && y1 <= y2) {
        cout << "1 " << x1 << " " << y1 << "\n";
    } else {
        cout << "0\n";
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
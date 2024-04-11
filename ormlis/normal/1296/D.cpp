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
    int n, a, b, k; cin >> n >> a >> b >> k;
    int ans = 0;
    vector<int> v;
    range(i, n) {
        int h; cin >> h;
        h = (h - 1) % (a + b) + 1;
        if (h <= a) {
            ans++;
        } else {
            v.push_back(h);
        }
    }
    sort(all(v));
    for(auto x: v) {
        int t = (x - 1) / a;
        if (t <= k) {
            k -= t;
            ans++;
        } else {
            break;
        }
    }
    cout << ans << '\n';
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
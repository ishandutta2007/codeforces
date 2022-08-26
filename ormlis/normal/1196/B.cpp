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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    vector<int> ans;
    int cur = 0;
    range(i, n) {
        cur += a[i];
        if (cur % 2) {
            ans.push_back(i);
            cur = 0;
        }
        if (ans.size() == k) {
            break;
        }
    }
    if (ans.size() == k) {
        cur = 0;
        for (int i = ans.back() + 1; i < n; ++i) {
            cur += a[i];
        }
        if (cur % 2 == 0) {
            cout << "YES\n";
            range(i, k - 1) cout << ans[i] + 1 << " ";
            cout << n << '\n';
            return;
        }
    }
    cout << "NO\n";
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
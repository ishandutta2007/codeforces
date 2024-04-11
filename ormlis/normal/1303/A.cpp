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
const int maxN = 1e5 * 2;
ll md = 1000000007;

void solve() {
    string s; cin >> s;
    int first = 101;
    int last = -1;
    range(i, s.size()) {
        if (s[i] == '1') {
            first = min(first, i);
            last = max(last, i);
        }
    }
    int ans = 0;
    for(int i = first; i < last; ++i) {
        if (s[i] == '0') ans++;
    }
    cout << ans << '\n';
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
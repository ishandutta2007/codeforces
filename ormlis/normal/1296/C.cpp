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
    map<pair<int, int>, int> mp;
    pair<int, int> p = {0, 0};
    mp[p] = -1;
    int l = -2, r = n + 1;
    range(i, n) {
        char s; cin >> s;
        if (s == 'L') p.first--;
        if (s == 'R') p.first++;
        if (s == 'U') p.second++;
        if (s == 'D') p.second--;
        if (mp.find(p) != mp.end()) {
            if (r - l > i - mp[p]) {
                l = mp[p];
                r = i;
            }
        }
        mp[p] = i;
    }
    if (l == -2) {
        cout << "-1\n";
    } else {
        cout << l + 2 << ' ' << r + 1 << '\n';
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
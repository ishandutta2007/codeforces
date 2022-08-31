#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>

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
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    range(i, n) {
        cin >> p[i].first >> p[i].second;
    }
    if (n % 2) {
        cout << "NO";
        return;
    }
    int k = n / 2;
    range(i,k) {
        if (p[i + 1].first - p[i].first != p[i + k].first - p[(i + k + 1) % n].first || p[i + 1].second - p[i].second != p[i + k].second - p[(i + k + 1) % n].second) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
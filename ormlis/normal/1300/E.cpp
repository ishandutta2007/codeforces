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
    int n; cin >> n;
    vector<ll> a(n);
    range(i, n) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> cur = {{a[0], 1}};
    int sz = 0;
    for(int i = 1; i < n; ++i) {
        cur.emplace_back(a[i], 1);
        sz++;
        while (sz >= 1 && cur[sz].first * cur[sz - 1].second < cur[sz - 1].first * cur[sz].second) {
            cur[sz - 1].first += cur[sz].first;
            cur[sz - 1].second += cur[sz].second;
            cur.pop_back();
            sz--;
        }
    }
    cout << setprecision(15) << fixed;
    int j = 0;
    for(auto p: cur) {
        int i = j + p.second;
        double x = (double)p.first / (double)p.second;
        while(j < i) {
            cout << x << "\n";
            j++;
        }
    }
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
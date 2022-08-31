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
    ll n; int m; cin >> n >> m;
    vector<ll> a(m, 0);
    range(i, m) cin >> a[i];
    sort(all(a));
    vector<pair<ll, int>> b;
    range(i, m) {
        if (b.empty() || b.back().first != a[i]) b.emplace_back(a[i], 0);
        b.back().second++;
    }
    ll d = 1;
    ll add = 0;
    int j = 0;
    int op = 0;
    range(i, 65) {
        if (j != b.size() && b[j].first == d) {
            add += b[j].second;
            j++;
        }
        if (n & d) {
            if (add) add--;
            else {
                if (j == b.size()) {
                    cout << -1 << "\n";
                    return;
                }
                b[j].second--;
                ll cur = b[j].first;
                while(cur != d) {
                    cur /= 2;
                    op++;
                    add = add * 2 + 1;
                }
            }
        }
        add /= 2;
        d *= 2;
    }
    cout << op << "\n";
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
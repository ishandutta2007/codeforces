#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;
ll md = 1000000007;


void solve() {
    int n, k; cin >> n;
    vector<pair<ll, ll>> a(n);
    range(i, n) cin >> a[i].first;
    range(i, n) cin >> a[i].second;
    sort(all(a));
    multiset<ll> cur;
    ll current = 0;
    ll ans = 0;
    ll curans = 0;
    range(i, n) {
        ll f = a[i].first;
        ll s = a[i].second;
        while (current < f && !cur.empty()) {
            curans -= *cur.rbegin();
            ans += curans;
            cur.erase(--cur.end());
            current += 1;
        }
        curans += s;
        cur.insert(s);
        current = f;
    }
    while (!cur.empty()) {
        curans -= *cur.rbegin();
        ans += curans;
        cur.erase(--cur.end());
        current += 1;
    }
    cout << ans;
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
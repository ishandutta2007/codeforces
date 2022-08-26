#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 4000001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    ll k;

    int n, m; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    range(i, n) cin >> a[i];
    range(i, m) cin >> b[i];
    vector<ll> divs;
    for(ll i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            divs.push_back(i);
            if (i != k / i) divs.push_back(k/i);
        }
    }
    vector<int> s(m+1, 0);
    int r = 0;
    range(l, m) {
        while((r < m && b[r] == 1) || r < l) r++;
        s[r-l]++;
    }
    for(int i = m - 1; i >= 0; --i) {
        s[i] += s[i+1];
    }
    ll ans = 0;
    for(auto x: divs) {
        r = 0;
        range(l, n) {
            while ((r < n && a[r] == 1) || r < l) r++;
            if (r - l >= x) {
                if (k/x<=m) ans += s[k/x];
            }
        }
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
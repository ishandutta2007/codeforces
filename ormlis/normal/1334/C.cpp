#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    int mi = 0;
    vector<pair<ll, ll>> a(n);
    range(i, n) cin >> a[i].first >> a[i].second;
    range(i, n) a[i].second = min(a[i].second, a[(i+1)%n].first);
    range(i, n) {
        if (a[i].second < a[mi].second) mi = i;
    }
    int start = (mi + 1) % n;
    ll ans = a[start].first;
    ll prev = a[start].second;
    for(int i = (start + 1) % n; i != start; i = (i + 1) % n) {
        a[i].first -= prev;
        ans += max(0ll, a[i].first);
        prev = a[i].second;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
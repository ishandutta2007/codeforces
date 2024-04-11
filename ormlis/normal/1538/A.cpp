#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 4e5;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int mn = min_element(all(a)) - a.begin();
    int mx = max_element(all(a)) - a.begin();
    if (mn > mx) swap(mn, mx);
    cout << min({mx + 1, n - mn, n - mx + mn + 1}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
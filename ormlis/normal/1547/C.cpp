#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 1e7 + 1;
const int md = 1e9 + 7;

void solve() {
    int k, n, m; cin >> k >> n >> m;
    vector<int> a(n), b(m);
    range(i, n) cin >> a[i];
    range(i, m) cin >> b[i];
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n || j < m) {
        if (i < n && a[i] <= k) {
            k += (a[i] == 0);
            ans.push_back(a[i]);
            i++;
        } else if (j < m && b[j] <= k) {
            k += (b[j] == 0);
            ans.push_back(b[j]);
            j++;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for(auto &x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
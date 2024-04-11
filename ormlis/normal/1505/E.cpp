#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int h, w; cin >> h >> w;
    vector<string> a(h);
    range(i, h) cin >> a[i];
    int i = 0, j = 0;
    int ans = 0;
    while(i != h - 1 || j != w - 1) {
        if (a[i][j] == '*') ans++;
        if (i == h - 1) {
            j++;
            continue;
        }
        if (j == w - 1) {
            i++;
            continue;
        }
        if (a[i + 1][j] == '*') i++;
        else j++;
    }
    if (a[i][j] == '*') ans++;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
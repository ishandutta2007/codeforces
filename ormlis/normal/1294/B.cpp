#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1000001;
ll md = 1000000007;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> cor(n);
    range(i, n) cin >> cor[i].first >> cor[i].second;
    sort(all(cor));
    int x1 = 0, y1=0;
    string ans = "";
    range(i, n) {
        int x2 = cor[i].first;
        int y2 = cor[i].second;
        if (x1 > x2 || y1 > y2) {
            cout << "NO\n";
            return;
        }
        range(j, x2 - x1) ans += "R";
        range(j, y2 - y1) ans += "U";
        y1 = y2;
        x1 = x2;
    }
    cout << "YES\n";
    cout << ans << '\n';
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
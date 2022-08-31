#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    string s; cin >> s;
    vector<int> maxi(3, -1e9);
    int ans = 1e9;
    range(i, s.size()) {
        maxi[s[i] - '1'] = i;
        int m = 1e9;
        range(j, 3) m = min(m, maxi[j]);
        ans = min(ans, i - m);
    }
    if (ans > s.size()) {
        cout << "0\n";
        return;
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int P = 998244353;
int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n,k ; cin >> n >> k;
    string s; cin >> s;
    int ans = 0;
    vector<map<char, int>> c(k);
    range(i, n) {
        int pos = min(i % k, k - 1 - i % k);
        c[pos][s[i]]++;
    }
    range(i, k / 2 + k % 2) {
        int mx = 0;
        for(auto &x: c[i]) mx = max(mx, x.second);
        if (k % 2 == 1 && i == k / 2) {
            ans += n / k - mx;
        } else {
            ans += n / k * 2 - mx;
        }
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
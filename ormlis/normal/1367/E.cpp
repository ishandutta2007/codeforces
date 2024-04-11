#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(26);
    range(i, n) {
        char a;
        cin >> a;
        cnt[a - 'a']++;
    }
    for (int len = n; len >= 1; --len) {
        int period = __gcd(len, k);
        int need = len / period;
        int res = 0;
        range(i, 26) res += cnt[i] / need;
        if (res >= period) {
            cout << len << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
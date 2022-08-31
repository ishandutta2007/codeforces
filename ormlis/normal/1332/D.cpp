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
    int k; cin >> k;
    cout << "2 3\n";
    cout << (1 << 18) - 1 << " " << k << " " << 0 << "\n";
    cout << (1 << 17) << " " << (1 << 17) + k << " " << k << "\n";
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
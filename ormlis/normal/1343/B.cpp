#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    if (n % 4 != 0) {
        cout << "NO\n";
        return;
    }
    vector<int> a(n);
    int cur = 1;
    for(int i = 0, j = n - 1; i < n / 2; ++i, --j) {
        if (cur & 1) {
            a[i] = cur + 1;
            a[j] = cur;
        } else {
            a[i] = cur;
            a[j] = cur + 1;
        }
        cur += 3;
    }
    cout << "YES\n";
    range(i, n) cout << a[i] << " ";
    cout << '\n';
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
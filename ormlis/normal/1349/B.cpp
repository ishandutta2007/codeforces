#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<int> bal(n);
    int cbal = 0;
    bool ans = false;
    bool find = false;
    range(i, n) {
        bal[i] = cbal;
        if (a[i] >= k) cbal++;
        else cbal--;
        if (k == a[i]) find = true;
        if (i && cbal - bal[i-1] > 0) ans = true;
        if (i) bal[i] = min(bal[i], bal[i-1]);
    }
    if (!find) ans = false;
    if (n == 1 && k == a[0]) ans = true;
    if (ans) cout << "yes\n";
    else cout << "no\n";
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
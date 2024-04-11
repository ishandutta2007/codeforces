#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace __gnu_pbds;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 4e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    int s1 = a[0], s2 = 0;
    range(i, n) {
        int x = min(a[i] - s2, s1);
        if (x < 0) {
            cout << "NO\n";
            return;
        }
        a[i] -= x;
        s1 = min(s1, x);
        s2 = max(s2, a[i]);
    }
    cout << "YES\n";
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
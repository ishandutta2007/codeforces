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
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
     int n; cin >> n;
     vector<int> a, b;
     range(i, n * 2) {
         int x, y; cin >> x >> y;
         if (x == 0) a.push_back(abs(y));
         else b.push_back(abs(x));
     }
     sort(all(a));
     sort(all(b));
     ld result = 0;
     range(i, n) {
         result += sqrtl(1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
     }
     cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
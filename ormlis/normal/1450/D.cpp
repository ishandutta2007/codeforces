#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int L = 0, R = n - 1;
    int cnt = 0;
    vector<int> c(n);
    range(i, n) c[a[i] - 1]++;
    range(i, n) {
        if (c[i] == 0) break;
        cnt++;
        if (a[L] != i + 1 && a[R] != i + 1) {
            break;
        }
        if (a[L] == i + 1) {
            L++;
        }
        if (a[R] == i + 1) {
            R--;
        }
        if (c[i] != 1) break;
    }
    auto b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());

    if (b.size() == n) cout << '1';
    else cout << '0';
    for(int i = 1; i < n; ++i) {
        if (n - i <= cnt) cout << '1';
        else cout << '0';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
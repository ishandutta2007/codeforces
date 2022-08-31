#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 2e6 + 1000;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int l, int r) {
        if (l == r) return -1;
        cout << "? " << l + 1 << ' ' << r + 1 << endl;
        int x;
        cin >> x;
        x--;
        return x;
    };
    int p = ask(0, n - 1);
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (p < mid) {
            int x = ask(min(l, p), mid - 1);
            if (x != p) {
                l = mid;
            } else {
                r = mid;
            }
        } else {
            int x = ask(mid, max(p, r - 1));
            if (x != p) {
                r = mid;
            } else {
                l = mid;
            }
        }
    }
    cout << "! " << l + 1 << endl;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
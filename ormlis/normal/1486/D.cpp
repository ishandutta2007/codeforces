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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    auto b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    auto check = [&] (int x) {
        int mn = 0;
        int Lx = 0;
        int Rx = 0;
        range(i, n) {
            if (a[i] >= x) Rx++;
            else Rx--;
            if (i - k >= 0) {
                if (a[i-k] >= x) Lx++;
                else Lx--;
                mn = min(mn, Lx);
            }
            if (i - k + 1 >= 0) {
                if (Rx > mn) return true;
            }
        }
        return false;
    };
    int L = 0, R = b.size();
    while(R - L > 1) {
        int mid = (R + L) / 2;
        if (check(b[mid])) {
            L = mid;
        } else {
            R = mid;
        }
    }
    cout << b[L] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    auto check = [&] (int x) {
        int last = 0;
        range(i, n) {
            if (a[i] <= last) {
                int need = last - a[i];
                if (need > x) return false;
                continue;
            }
            int need = last - a[i] + m;
            if (need <= x) continue;
            last = a[i];
        }
        return true;
    };
    int l = -1, r = m;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}
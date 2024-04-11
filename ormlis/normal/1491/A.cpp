#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int q;
    int n; cin >> n;
    cin >> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    ar<int, 2> cnt = {0, 0};
    range(i, n) cnt[a[i]]++;
    range(_, q) {
        int t; cin >> t;
        int x; cin >> x;
        if (t == 1) {
            x--;
            cnt[a[x]]--;
            a[x] ^= 1;
            cnt[a[x]]++;
            continue;
        }
        if (cnt[1] >= x) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int _ = 0; _ < 2; _++) {
        ll cnt = 0;
        bool good = 0;
        for (int i = 0; i < k; i++) {
            int val = a[i] / m;
            if (val >= 2) {
                cnt += val;
                if (val > 2) {
                    good = 1;
                }
            }
        }
        if ((good || n % 2 == 0) && cnt >= n) {
            cout << "Yes\n";
            return;
        }
        swap(n, m);
    }
    cout << "No\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
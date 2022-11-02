#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

ll solve(int n, int k, vector<int> a) {
    vector<int> ord(n), used(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){return a[i] + i > a[j] + j;});
    for (int i = 0; i < k; i++) {
        used[ord[i]] = 1;
    }
    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            cnt++;
        } else {
            ans += cnt + a[i];
        }
    }
    return ans;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(n, k, a) << endl;
    }
    return 0;
}
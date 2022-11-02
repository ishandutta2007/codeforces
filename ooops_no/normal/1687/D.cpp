#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    shuffle(a.begin() + 1, a.end(), rnd);
    for (ll i = 1;;i++) {
        if (i * i + i < a[0]) continue;
        ll L = max(0ll, i * i - a[0]), R = i * i + i - a[0];
        for (int j = 1; L <= R && j < n; j++) {
            ll k = sqrt(a[j] + L);
            if (a[j] + L <= k * (k + 1)) {
                R = min(R, k * (k + 1) - a[j]);
            } else {
                L = max(L, (k + 1) * (k + 1) - a[j]);
            }
        }
        if (L <= R) {
            cout << L << endl;
            return 0;
        }
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld double
#define ll long long

mt19937 rnd(51);

void solve(int n, vector<int> a) {
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    int sz = n / 2;
    for (int i = 1; i < sz; i++) {
        if (a[i] == a[i + sz - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < sz; i++) {
        cout << a[i] << ' ' << a[i + sz] << ' ';
    }
    cout << endl;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(n, a);
    }
    return 0;
}
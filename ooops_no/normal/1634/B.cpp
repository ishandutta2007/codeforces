#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

bool check(string s) {
    return s == (string){s.rbegin(), s.rend()};
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y, res = 0;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            res ^= a[i];
        }
        if ((res + x) % 2 == y % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
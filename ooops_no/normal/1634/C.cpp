#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

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
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                cout << i << endl;
            }
            continue;
        }
        if (n % 2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    cout << i + j * n + 1 << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}
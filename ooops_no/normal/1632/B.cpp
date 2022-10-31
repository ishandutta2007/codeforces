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
        int n;
        cin >> n;
        int k = 0;
        while ((1 << k) < n) {
            k++;
        }
        k--;
        for (int i = (1 << k) - 1; i >= 0; i--) {
            cout << i << ' ';
        }
        for (int i = (1 << k); i < n; i++) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
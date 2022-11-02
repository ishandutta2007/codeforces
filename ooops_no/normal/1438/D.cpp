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
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) a[0] ^= a[i];
    if (n % 2 == 0 && a[0] != 0) cout << "NO" << endl;
    else{
        cout << "YES\n" << n - 2 + n % 2 << endl;
        for (int i = 1; i + 1 < n; i += 2) cout << "1 " << i + 1 << " " << i + 2 << endl;
        for (int i = 1; i + 1 < n; i += 2) cout << "1 " << i + 1 << " " << i + 2 << endl;
    }
    return 0;
}
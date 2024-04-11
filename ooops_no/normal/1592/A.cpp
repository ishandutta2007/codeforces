#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        int cnt = h / (a[0] + a[1]);
        h -= cnt * (a[0] + a[1]);
        if (h == 0) cout << cnt * 2 << endl;
        else if (h <= a[0]) cout << cnt * 2 + 1 << endl;
        else cout << cnt * 2 + 2 << endl;
    }
    return 0;
}
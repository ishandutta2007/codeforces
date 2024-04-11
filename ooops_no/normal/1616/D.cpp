#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

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
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), was(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int x;
        cin >> x;
        for (int i = 0; i < n; i++){
            a[i] -= x;
        }
        int ans = n;
        for (int i = 0; i < n; i++){
            if (was[i] || was[i + 1]) continue;
            if (i + 1 < n && a[i] + a[i + 1] < 0){
                was[i + 1] = 1;
                ans--;
                continue;
            }
            if (i + 2 < n && a[i] + a[i + 1] + a[i + 2] < 0){
                was[i + 2] = 1;
                ans--;
                continue;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
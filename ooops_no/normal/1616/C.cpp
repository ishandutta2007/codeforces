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
        vector<ld> a(n);
        int ans = n - 1;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                ld val = (a[j] - a[i]) / (j - i), res = a[i];
                int cnt = 0;
                for (int k = i + 1; k < n; k++){
                    res += val;
                    if (abs(a[k] - res) > 0.0000000001) cnt++;
                }
                res = a[i];
                for (int k = i - 1; k >= 0; k--){
                    res -= val;
                    if (abs(a[k] != res) > 0.0000000001) cnt++;
                }
                ans = min(ans, cnt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
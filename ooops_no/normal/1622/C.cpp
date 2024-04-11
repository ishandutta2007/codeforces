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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), pr(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        pr[0] = a[0];
        for (int i = 1; i < n; i++){
            pr[i] += pr[i - 1] + a[i];
        }
        int ans = 1e18;
        for (int i = 1; i < n; i++){
            int l = -1e10, r = a[0] + 1;
            while(r - l > 1){
                int mid = (r + l) / 2;
                if (pr[n - i - 1] - a[0] + mid * (i + 1) <= k){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            ans = min(ans, a[0] - l + i);
        }
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += a[i];
        }
        ans = min(ans, max(0ll, sum - k));
        cout << ans << endl;
    }
    return 0;
}
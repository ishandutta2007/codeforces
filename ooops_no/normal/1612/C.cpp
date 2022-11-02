#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
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
        int k, x;
        cin >> k >> x;
        int l = 0, r = 2 * k - 1;
        while(r - l > 1){
            int mid = (r + l) / 2;
            int cnt = 0;
            if (mid <= k){
                cnt = mid * (mid + 1) / 2;
            }
            else{
                cnt = k * (k + 1) / 2 + k * (k - 1) / 2;
                int need = 2 * k - mid;
                cnt -= need * (need - 1) / 2;
            }
            if (cnt >= x){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        cout << r << endl;
    }
    return 0;
}
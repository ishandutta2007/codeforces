#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
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
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> a;
        for (int i = 0; i < n; i++){
            int b;
            cin >> b;
            if (b >= l && b <= r){
                a.pb(b);
            }
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (auto to : a){
            if (k >= to){
                k -= to;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
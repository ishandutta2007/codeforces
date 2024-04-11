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
        map<int,int> mp;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            mp[abs(a)]++;
        }
        int ans = 0;
        for (auto to : mp){
            if (to.first == 0) ans++;
            else ans += min(to.second, 2ll);
        }
        cout << ans << endl;
    }
    return 0;
}
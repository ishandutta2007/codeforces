#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            mp[v[i]].pb(i);
        }
        int ans = 0;
        for (auto to : mp){
            vector<int> v = to.second;
            int sum = 0;
            for (auto to : v){
                sum += (n - to);
            }
            for (auto to : v){
                sum -= (n - to);
                ans += (to + 1) * sum;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
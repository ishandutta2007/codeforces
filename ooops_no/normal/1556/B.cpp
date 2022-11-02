#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

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
        int n;
        cin >> n;
        vector<int> v(n);
        vector<vector<int>> cnt(2);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            v[i] %= 2;
            cnt[v[i]].pb(i);
        }
        vector<int> a, b;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) a.pb(i);
            else b.pb(i);
        }
        int ans = 1e18;
        if (a.size() == cnt[0].size() && b.size() == cnt[1].size()){
            int cntt = 0;
            for (int i = 0; i < a.size(); i++){
                cntt += abs(a[i] - cnt[0][i]);
            }
            for (int i = 0; i < b.size(); i++){
                cntt += abs(b[i] - cnt[1][i]);
            }
            ans = min(ans, cntt);
        }
        if (a.size() == cnt[1].size() && b.size() == cnt[0].size()){
            int cntt = 0;
            for (int i = 0; i < a.size(); i++){
                cntt += abs(a[i] - cnt[1][i]);
            }
            for (int i = 0; i < b.size(); i++){
                cntt += abs(b[i] - cnt[0][i]);
            }
            ans = min(ans, cntt);
        }
        if (ans == 1e18) cout << -1 << endl;
        else cout << ans / 2 << endl;
    }
    return 0;
}
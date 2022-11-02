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
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> h(n), sum(m);
        set<pair<int,int>> st;
        vector<vector<int>> ans(m);
        int j = 0;
        for (int i = 0; i < n; i++){
            cin >> h[i];
            if (j == m){
                ans[m - 1].pb(i);
                sum[m - 1] += h[i];
            }
            else{
                ans[j].pb(i);
                sum[j] += h[i];
                j++;
            }
        }
        for (int i = 0; i < m; i++){
            st.insert({sum[i], i});
        }
        while(abs(st.rbegin()->first - st.begin()->first) > x){
            auto v = *st.rbegin(), vv = *st.begin();
            st.erase(v);
            st.erase(vv);
            int val = ans[v.second].back();
            ans[v.second].pop_back();
            sum[v.second] -= h[val];
            sum[vv.second] += h[val];
            ans[vv.second].pb(val);
            st.insert({sum[v.second], v.second});
            st.insert({sum[vv.second], vv.second});
        }
        vector<int> show(n);
        for (int i = 0; i < m; i++){
            for (auto to : ans[i]) show[to] = i + 1;
        }
        cout << "YES\n";
        for (auto to : show){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}
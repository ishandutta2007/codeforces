    #include<bits/stdc++.h>

    using namespace std;

    /*

    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;

    tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

    */
    /*

    st.find_by_order();
    st.order_of_key();

    */

    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("fast-math")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

    #define pb push_back
    #define ld double
    #define int long long

    mt19937 rnd(49);

    int32_t main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin >> t;
        while (t--){
            int n, k, cnt = 0;
            cin >> n >> k;
            map<int,int> mp;
            vector<int> v(n), ans(n);
            for (int i = 0; i < n; i++){
                cin >> v[i];
                if (mp[v[i]] == 0){
                    if (v[i] * 2 != k){
                        mp[v[i]] = 1;
                        mp[k - v[i]] = 2;
                    }
                }
                if (v[i] * 2 != k){
                    ans[i] = mp[v[i]] - 1;
                }
                else{
                    cnt++;
                }
            }
            cnt /= 2;
            for (int i = 0; i < n; i++){
                if (v[i] * 2 == k){
                    if (cnt != 0){
                        ans[i] = 1;
                        cnt--;
                    }
                    else{
                        ans[i] = 0;
                    }
                }
            }
            for (auto to : ans){
                cout << to << " ";
            }
            cout << endl;
        }
        return 0;
    }
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double

mt19937 rnd(51);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++){
            cin >> v[i];
        }
        for (int j = 2; j <= 1000; j++){
            vector<int> d(j);
            int ans = 0;
            for (auto to : v){
                d[to % j]++;
            }
            for (int i = 1; i < j; i++){
                ans += min(d[i], d[j - i]);
                if (i == j - i){
                    ans += d[i];
                }
            }
            ans /= 2;
            ans += d[0] / 2;
            if (ans >= n - 1){
                vector<pair<int,int>> lol;
                vector<int> a;
                for (int i = 0; i < v.size(); i++){
                    if (v[i] % j == 0){
                        a.pb(i + 1);
                    }
                }
                for (int i = 1; i < a.size(); i += 2){
                    lol.pb({a[i], a[i - 1]});
                }
                map<int, vector<int>> mp;
                for (int i = 0; i < v.size(); i++){
                    mp[v[i] % j].pb(i + 1);
                }
                for (int i = 1; i < j / 2; i++){
                    for (int k = 0; k < min(d[i], d[j - i]); k++){
                        lol.pb({mp[i][k], mp[j - i][k]});
                    }
                }
                if (j % 2 == 0){
                    vector<int> a;
                    for (int i = 0; i < v.size(); i++){
                        if (v[i] % j == j / 2){
                            a.pb(i + 1);
                        }
                    }
                    for (int i = 1; i < a.size(); i += 2){
                        lol.pb({a[i], a[i - 1]});
                    }
                }
                if (lol.size() == n){
                    lol.pop_back();
                }
                for (auto to : lol){
                    cout << to.first << ' ' << to.second << endl;
                }
                break;
            }
        }
    }
    return 0;
}
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
#define int long long

mt19937 rnd(51);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
        int n, m, x;
        cin >> n >> x >> m  ;
        vector<pair<int,int>> v;
        v.pb({x, x});
        for (int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            bool x = 0;
            for (int j = 0; j < v.size(); j++){
                if (v[j].second >= l && v[j].first <= r && !x){
                    x = 1;
                    v.pb({l, r});
                }
            }
        }
        int mn = v[0].first, mx = v[0].second;
        for (int i = 0; i < v.size(); i++){
            mn = min(mn, v[i].first);
            mx = max(mx, v[i].second);
        }
        cout << mx - mn + 1 << endl;
	}
	return 0;
}
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
	int n;
	cin >> n;
	vector<vector<int>> d(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++){
            d[i][j] = s[j - 1] - '0';
            if (d[i][j] == 0){
                d[i][j] = 1e9;
            }
        }
	}
	int m;
	cin >> m;
	vector<int> p(m);
	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; i++){
        cin >> p[i];
	}
	for (int i = m - 1; i > -1; i--){
        v[p[i]].pb(i);
	}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	vector<int> ans;
	ans.pb(p[0]);
	v[p[0]].pop_back();
	int last = 0;
	while(last != m - 1){
        int mx = 0, j = 0;
        for (int i = 1; i <= n; i++){
            if (v[i].size() != 0){
                if (p[last] != i && d[p[last]][i] == v[i].back() - last && v[i].back() - last > mx){
                    mx = v[i].back() - last;
                    j = v[i].back();
                }
            }
        }
        for (int i = last + 1; i <= j; i++){
            v[p[i]].pop_back();
        }
        ans.pb(p[j]);
        last = j;
	}
	cout << ans.size() << endl;
	for (auto to : ans){
        cout << to << " ";
	}
	return 0;
}
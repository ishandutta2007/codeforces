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

const int N = 1e5 + 10;
vector<pair<int, int>> g[N], gr[N];
vector<bool> used(N);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	map<pair<pair<int,int>, int>, int> now;
	vector<pair<pair<int,int>, int>> v;
	for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        gr[b].pb({a, c});
        v.pb({{a, b}, c});
	}
	vector<int> d(N, 1e18);
	d[s] = 0;
	set<pair<int,int>> st;
	st.insert({d[s], s});
	while(!st.empty()){
        auto v = *st.begin();
        st.erase(st.begin());
        for (auto to : g[v.second]){
            if (d[to.first] > d[v.second] + to.second){
                st.erase({d[to.first], to.first});
                d[to.first] = d[v.second] + to.second;
                st.insert({d[to.first], to.first});
            }
        }
	}
	int ans = d[t];
	vector<int> d1(N, 1e18);
	d1[t] = 0;
	st.insert({d1[t], t});
	vector<pair<int, pair<int, pair<int, pair<int, int>>>>> lol;
	while(!st.empty()){
        auto v = *st.begin();
        st.erase(st.begin());
        for (auto to : gr[v.second]){
            if (d1[to.first] > d1[v.second] + to.second){
                st.erase({d1[to.first], to.first});
                d1[to.first] = d1[v.second] + to.second;
                st.insert({d1[to.first], to.first});
            }
        }
	}
	for (auto to : v){
        if (d[to.first.first] + to.second + d1[to.first.second] == ans){
            lol.pb({d[to.first.first], {1, {to.first.first, {to.first.second, to.second}}}});
            lol.pb({d[to.first.second], {-1, {to.first.first, {to.first.second, to.second}}}});
        }
	}
	sort(lol.begin(), lol.end());
	int cnt = 0;
	for (int i = 0; i < lol.size(); i++){
        cnt += lol[i].second.first;
        if (cnt == 1 && lol[i + 1].second.first == -1 && lol[i].second.first == 1){
            now[{{lol[i].second.second.first, lol[i].second.second.second.first}, lol[i].second.second.second.second}] = 1;
        }
	}
	for (auto t : v){
        if (now[t]){
            cout << "YES\n";
            continue;
        }
        auto to = t.first;
        if (d[to.first] + d1[to.second] + 1 < ans){
            cout << "CAN " << t.second - (ans - d[to.first] - d1[to.second]) + 1 << endl;
        }
        else{
            cout << "NO\n";
        }
	}
	return 0;
}
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
vector<pair<int, int>> g[N];
vector<int> d(N, 1e18);

pair<int, int> func(int a, int b) {
	return { min(a, b), max(a, b) };
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> v;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.pb({{a, b}, c });
		g[a].pb({ b, c });
		g[b].pb({ a, c });
	}
	queue<int> q;
	q.push(n);
	d[n] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d[to.first] == 1e18) {
				d[to.first] = d[v] + 1;
				q.push(to.first);
			}
		}
	}
	int ans = d[1];
	vector<int> d1(N, 1e18), cnt(N, -1);
	vector<int> par(N);
	q.push(1);
	d1[1] = 0;
	cnt[1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d1[to.first] == 1e18) {
				d1[to.first] = d1[v] + 1;
			}
			if (d[to.first] == ans - d1[to.first] && d1[to.first] > d1[v]) {
				if (cnt[v] + to.second > cnt[to.first]) {
					cnt[to.first] = cnt[v] + to.second;
					par[to.first] = v;
				}
				q.push(to.first);
			}
		}
	}
	map<pair<int, int>, bool> used;
	int now = n;
	while (now != 1) {
		used[func(now, par[now])] = 1;
		now = par[now];
	}
	vector<pair<pair<int, int>, int>> lol;
	for (auto to : v) {
		if (used[func(to.first.first, to.first.second)] && to.second == 0) {
			lol.pb({ to.first, (to.second + 1) % 2 });
		}
		if (used[func(to.first.first, to.first.second)] == 0 && to.second == 1) {
			lol.pb({ to.first, (to.second + 1) % 2 });
		}
	}
	cout << lol.size() << endl;
	for (auto to : lol) {
		cout << to.first.first << " " << to.first.second << " " << to.second << endl;
	}
	return 0;
}
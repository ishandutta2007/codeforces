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
vector<int> g[N];
vector<bool> used(N);
vector<map<int, int>> ans(N);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, M;
	cin >> n >> m;
	M = sqrt(n + 5);
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.pb({ c, {a, b} });
	}
	sort(v.begin(), v.end());
	vector<set<int>> check;
	int now = 1, j = 0;
	while (now <= m)
	{
		set<int> st;
		vector<pair<int, int>> a;
		while (j < v.size() && v[j].first == now)
		{
			st.insert(v[j].second.first);
			st.insert(v[j].second.second);
			a.pb(v[j].second);
			j++;
		}
		for (auto to : st)
		{
			used[to] = 0;
			g[to].clear();
		}
		for (auto to : a) {
			g[to.first].pb(to.second);
			g[to.second].pb(to.first);
		}
		for (auto to : st)
		{
			if (!used[to])
			{
				set<int> lol;
				queue<int> q;
				q.push(to);
				while (!q.empty())
				{
					int v = q.front();
					q.pop();
					lol.insert(v);
					used[v] = 1;
					for (auto to : g[v])
					{
						if (!used[to])
						{
							q.push(to);
							used[to] = 1;
						}
					}
				}
				if (lol.size() > M)
				{
					check.pb(lol);
				}
				else
				{
					for (auto to : lol)
					{
						for (auto t : lol)
						{
							ans[to][t]++;
						}
					}
				}
			}
		}
		now++;
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b, mx = 0;
		cin >> a >> b;
		for (int i = 0; i < check.size(); i++) {
			if (check[i].find(a) != check[i].end() && check[i].find(b) != check[i].end()) {
				mx++;
			}
		}
		cout << mx + ans[a][b] << endl;
	}
	return 0;
}
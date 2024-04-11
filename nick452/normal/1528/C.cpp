#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

vector<int> p1;
vector<int> p2;
vector<vector<int>> g1;
vector<vector<int>> g2;
vector<int> que;
vector<int> first;
vector<int> last;

int ret;
map<int, int> nodes;

void dfs2(int cur, int& count) {
	first[cur] = (count++);
	for (int next : g2[cur]) {
		dfs2(next, count);
	}
	last[cur] = (count++);
}

int is_contain(int l1, int r1, int l2, int r2) {
	return l1 <= l2 && r1 >= r2;
}

int is_contain(pair<int, int> l, pair<int, int> r) {
	return is_contain(l.first, l.second, r.first, r.second);
}

void dfs1(int cur)
{
	vector<pair<int, int>> added;
	vector<pair<int, int>> deleted;
	auto it = nodes.lower_bound(first[cur]);
	if (it != nodes.end() && is_contain({first[cur], last[cur]}, *it)) {

	} else {
		if (it != nodes.begin()) {
			auto it2 = it;
			--it2;
			if (is_contain(*it2, { first[cur], last[cur] })) {
				deleted.push_back(*it2);
				nodes.erase(it2);
			} 
		}
		added.push_back({ first[cur], last[cur] });
		nodes.insert({ first[cur], last[cur] });
	}
	ret = max(ret, (int)nodes.size());
	for (int next : g1[cur]) {
		dfs1(next);
	}

	for (auto x : added) {
		nodes.erase(x.first);
	}
	for (auto x : deleted) {
		nodes.insert(x);
	}
}

void one_case() {
	int n;
	cin >> n;
	p1 = vector<int>(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p; --p;
		p1[i] = p;
	}
	p2 = vector<int>(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p; --p;
		p2[i] = p;
	}

	g1 = vector<vector<int>>(n);
	for (int i = 1; i < n; ++i) {
		g1[p1[i]].push_back(i);
	}
	g2 = vector<vector<int>>(n);
	for (int i = 1; i < n; ++i) {
		g2[p2[i]].push_back(i);
	}

	first = vector<int>(n);
	last = vector<int>(n);
	int count = 0;
	dfs2(0, count);
	
	ret = 0;
	nodes.clear();
	dfs1(0);
	printf("%d\n", ret);
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		one_case();
	}
	return 0;
}
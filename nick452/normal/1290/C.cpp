#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int prev;
	int num[2];
	int fixed;
	int offset;

	int count() const {
		if (fixed >= 0) {
			return num[fixed ^ 1];
		} else {
			return min(num[0], num[1]);
		}
	}
};
vector<Node> state;

int results;

int get_root(int id) {
	if (state[id].prev < 0) {
		return id;
	}
	int root = get_root(state[id].prev);
	state[id].offset ^= state[state[id].prev].offset;
	state[id].prev = root;
	return root;
}

void add_node(int id, int to_be_fixed) {
	int root = get_root(id);
	if (state[root].fixed >= 0) {
		return;
	}
	results -= state[root].count();
	state[root].fixed = to_be_fixed ^ state[id].offset;
	results += state[root].count();
}

void add_edge(int id1, int id2, int to_be_fixed) {
	int root1 = get_root(id1);
	int root2 = get_root(id2);
	if (root1 == root2) {
		return;
	}
	Node& r1 = state[root1];
	Node& r2 = state[root2];
	results -= r1.count();
	results -= r2.count();
	r1.prev = root2;
	r1.offset = to_be_fixed ^ state[id1].offset ^ state[id2].offset;
	r2.num[0] += r1.num[r1.offset];
	r2.num[1] += r1.num[r1.offset ^ 1];
	if (r2.fixed < 0 && r1.fixed >= 0) {
		r2.fixed = (r1.offset ^ r1.fixed);
	}
	results += r2.count();
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> m >> n;
	string s;
	cin >> s;
	vector<vector<int>> mp(m);
	for (int i = 0; i < n; ++i) {
		int count;
		cin >> count;
		for (int j = 0; j < count; ++j) {
			int id;
			cin >> id;
			--id;
			mp[id].push_back(i);
		}
	}
	state = vector<Node>(n);
	for (int i = 0; i < n; ++i) {
		state[i].prev = -1;
		state[i].num[0] = 1;
		state[i].num[1] = 0;
		state[i].fixed = -1;
		state[i].offset = 0;
	}

	results = 0;
	for (int i = 0; i < n; ++i) {
		results += state[i].count();
	}

	for (int i = 0; i < m; ++i) {
		if (mp[i].size() == 1) {
			add_node(mp[i][0], s[i] != '1');
		} else if (mp[i].size() == 2) {
			add_edge(mp[i][0], mp[i][1], s[i] != '1');
		}
		printf("%d\n", results);
	}
	return 0;
}
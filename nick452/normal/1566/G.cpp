#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Container {
	vector<pair<ll, int>> a;
	ll s3;
};

Container build(const set<pair<ll, int>>& s) {
	Container c;
	auto it = s.begin();
	c.s3 = 0;
	for (int i = 0; i < 3; ++i) {
		if (it == s.end()) {
			c.s3 = 1e15;
			break;
		}
		c.a.push_back(*it);
		c.s3 += it->first;
		++it;
	}
	return c;
}

using Node = vector<pair<ll, int>>;

Node f(const Node& a, const Node& b) {
	Node c;
	int pa = 0;
	int pb = 0;
	c.reserve(3);
	while (pa < a.size() || pb < b.size()) {
		const auto& w = (pb >= b.size() || pa < a.size() && a[pa].first < b[pb].first ? a[pa++] : b[pb++]);
		int dup = 0;
		for (const auto& w2 : c) {
			if (w.second == w2.second) {
				dup = 1;
				break;
			}
		}
		if (dup) {
			continue;
		}
		c.push_back(w);
		if (c.size() >= 3) {
			break;
		}
	}
	return c;
}

void update_tree(vector<Node>& tree, int idx, int s, int t, int p, const Container& cg) {
	if (s == t) {
		tree[idx] = cg.a;
		return;
	}
	int m = (s + t) / 2;
	if (p <= m) {
		update_tree(tree, idx * 2 + 1, s, m, p, cg);
	}
	else {
		update_tree(tree, idx * 2 + 2, m + 1, t, p, cg);
	}
	tree[idx] = f(tree[idx * 2 + 1], tree[idx * 2 + 2]);
}

template<class Func>
void peek_tree(const vector<Node>& tree, int idx, int s, int t, int l, int r, Func func) {
	if (l > r || l > t || r < s) {
		return;
	}
	if (l <= s && r >= t) {
		func(tree[idx]);
		return;
	}
	int m = (s + t) / 2;
	peek_tree(tree, idx * 2 + 1, s, m, l, r, func);
	peek_tree(tree, idx * 2 + 2, m + 1, t, l, r, func);
}

int main()
{
#ifdef _MSC_VER
	ll cksum = 0;
	double time1 = (double)clock() / CLOCKS_PER_SEC;
	freopen("g-large.in", "r", stdin);
	//freopen("g.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	auto edge_id = [&](int a, int b) { return make_pair(min(a, b), max(a, b)); };

	map<pair<int, int>, ll> edge_id_to_cost;
	vector<set<pair<ll, int>>> g(n);
	vector<Container> cg(n);
	set<pair<ll, pair<int, int>>> edges;
	multiset<ll> s3_set;
	for (int i = 0; i < n; ++i) {
		cg[i].s3 = 1e15;
		s3_set.insert(cg[i].s3);
	}
	vector<Node> tree(n * 4);

	auto update = [&](int p) {
		s3_set.erase(s3_set.find(cg[p].s3));
		auto save = cg[p].a;
		cg[p] = build(g[p]);
		if (save != cg[p].a) {
			update_tree(tree, 0, 0, n - 1, p, cg[p]);
		}
		s3_set.insert(cg[p].s3);
	};
	auto add = [&](int a, int b, ll w) {
		edges.insert(make_pair(w, edge_id(a, b)));
		edge_id_to_cost[edge_id(a, b)] = w;
		g[a].insert({ w, b });
		g[b].insert({ w, a });
		update(a);
		update(b);
	};
	auto del = [&](int a, int b) {
		ll w = edge_id_to_cost[edge_id(a, b)];
		edges.erase(make_pair(w, edge_id(a, b)));
		g[a].erase({ w, b });
		g[b].erase({ w, a });
		update(a);
		update(b);
	};
	auto eval = [&]() -> ll {
		auto min_edge = *edges.begin();
		ll w0 = min_edge.first;
		int a = min_edge.second.first;
		int b = min_edge.second.second;
		if (a > b) {
			swap(a, b);
		}
		ll ret = 1e15;
		/*
		for (int c = 0; c < n; ++c) {
			if (c != a && c != b) {
				ret = min(ret, w0 + cg[c].extract(a, b));
			}
		}
		*/
		auto func = [&](const vector<pair<ll, int>>& node) {
			for (const auto& w : node) {
				if (w.second != a && w.second != b) {
					ret = min(ret, w0 + w.first);
					break;
				}
			}
		};
		peek_tree(tree, 0, 0, n - 1, 0, a - 1, func);
		peek_tree(tree, 0, 0, n - 1, a + 1, b - 1, func);
		peek_tree(tree, 0, 0, n - 1, b + 1, n - 1, func);
		for (const auto& ea : cg[a].a) {
			if (ea.second != b) {
				for (const auto& eb : cg[b].a) {
					if (eb.second != a && eb.second != ea.second) {
						ret = min(ret, ea.first + eb.first);
					}
				}
			}
		}
		ret = min(ret, *s3_set.begin());
		/*
		for (int i = 0; i < n; ++i) {
			ret = min(ret, cg[i].s3);
		}
		*/
		return ret;
	};


	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		ll w = c;
		edges.insert(make_pair(w, edge_id(a, b)));
		edge_id_to_cost[edge_id(a, b)] = w;
		g[a].insert({ w, b });
		g[b].insert({ w, a });
	}
	for (int i = 0; i < n; ++i) {
		update(i);
	}
#ifdef _MSC_VER
	printf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC - time1);
#endif

	printf("%lld\n", eval());

	int num_queries;
	cin >> num_queries;
	for (int query_id = 0; query_id < num_queries; ++query_id) {
		int is_add;
		cin >> is_add;
		if (is_add) {
			int a, b, c;
			cin >> a >> b >> c;
			--a;
			--b;
			add(a, b, c);
		}
		else {
			int a, b;
			cin >> a >> b;
			--a;
			--b;
			del(a, b);
		}
#ifdef _MSC_VER
		cksum += eval();
#else
		printf("%lld\n", eval());
#endif
	}
#ifdef _MSC_VER
	printf("cksum = %lld\n", cksum);
	printf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC - time1);
#endif
	return 0;
}
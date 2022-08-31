#include <bits/stdc++.h>
using namespace std;

template <int N>
struct bitwise_trie {
	struct node {
		int cnt;
		std::array<int, 2> next;
		node() : cnt(0) {
			next.fill(-1);
		}
	};

	std::vector<node> t;

	bitwise_trie() : t(1) {}

	void insert(const std::bitset<N> &b) {
		int cur = 0;
		t[cur].cnt += 1;
		for (int i = N - 1; i >= 0; i--) {
			if (t[cur].next[b[i]] == -1) {
				t[cur].next[b[i]] = (int) t.size();
				t.emplace_back();
			}
			cur = t[cur].next[b[i]];
			t[cur].cnt += 1;
		}
	}

	int count(const std::bitset<N> &b) {
		int cur = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (t[cur].next[b[i]] == -1) {
				return false;
			}
			cur = t[cur].next[b[i]];
		}
		return t[cur].cnt;
	}

	node &operator[](int i) {
		return t[i];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	long long cost = 0;
	auto recurse = [&](const vector<int> &v, int bit, const auto &self) -> void {
		if (v.empty()) {
			return;
		}
		vector<int> v0, v1;
		for (auto &x : v) {
			if (x >> bit & 1) {
				v1.push_back(x);
			} else {
				v0.push_back(x);
			}
		}
		if (bit != 0) {
			self(v0, bit - 1, self);
			self(v1, bit - 1, self);
		}
		if (v0.empty() || v1.empty()) {
			return;
		}
		bitwise_trie<30> t;
		if (v0.size() > v1.size()) {
			v0.swap(v1);
		}
		for (auto &x : v0) {
			t.insert(x);
		}
		int ans = INT_MAX;
		for (auto &x : v1) {
			int cur_ans = 0, cur = 0;
			for (int i = 29; i >= 0; i--) {
				bool f = (x >> i & 1);
				if (t[cur].next[f] != -1) {
					cur = t[cur].next[f];
				} else {
					cur_ans |= 1 << i;
					cur = t[cur].next[1 ^ f];
				}
			}
			ans = min(ans, cur_ans);
		}
		cost += ans;
	};

	recurse(a, 29, recurse);
	cout << cost << '\n';
	return 0;
}
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

	int n, k;
	cin >> n >> k;

	bitwise_trie<30> t;
	t.insert(0);

	t.t.reserve(30 * n + n);

	long long ans = 0;

	bitset<30> b = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		b ^= x;
		for (int cur = 0, d = 29; cur != -1; d--) {
			if (d == -1) {
				ans += t[cur].cnt;
				break;
			}
			if (k >> d & 1) {
				cur = t[cur].next[1 - b[d]];
			} else {
				if (t[cur].next[1 - b[d]] != -1) {
					ans += t[t[cur].next[1 - b[d]]].cnt;
				}
				cur = t[cur].next[b[d]];
			}
		}
		t.insert(b);
	}
	cout << ans << '\n';
	return 0;
}
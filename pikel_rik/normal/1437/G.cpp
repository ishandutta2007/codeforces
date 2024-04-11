#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <char f = 'a', size_t K = 26>
struct AhoCorasick {
	struct Node {
		bool leaf, segLeaf;
		char pch;
		int idx, p, link, exitLink;
		array<int, K> next;
		Node(int p, char pch): leaf(false), idx(-1), p(p), pch(pch), link(-1), exitLink(-1) {
			next.fill(-1);
		}
	};

	vector<Node> t;
	AhoCorasick(): t(1, Node(-1, ' ')) {}
	AhoCorasick(const vector<string>& s): t(1, Node(-1, ' ')) {
		for (int i = 0; i < s.size(); i++) {
			insert(s[i], i);
		}
	}

	int insert(const string& s) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				t[cur].next[ch - f] = (int)t.size();
				t.emplace_back(cur, ch);
			}
			cur = t[cur].next[ch - f];
		}
		return cur;
	}

	bool search(const string& s) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				return false;
			}
			cur = t[cur].next[ch - f];
		}
		return t[cur].leaf;
	}

	void process() {
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			if (x == 0 or t[x].p == 0) {
				t[x].link = 0;
			} else {
				t[x].link = t[t[t[x].p].link].next[t[x].pch - f];
				t[x].exitLink = t[t[x].link].leaf ? t[x].link : t[t[x].link].exitLink;
			}

			for (int i = 0; i < K; i++) {
				if (t[x].next[i] == -1) {
					t[x].next[i] = x == 0 ? 0 : t[t[x].link].next[i];
				} else {
					q.push(t[x].next[i]);
				}
			}
		}
	}

	Node& operator[](int i) {
		return t[i];
	}
};

const int N = 3e5 + 5;

int n, m, sus[N], id[N];
string s[N];
multiset<int> st[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	AhoCorasick<> t;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int cur = t.insert(s[i]);
		if (!t[cur].leaf) {
			id[i] = i;
			t[cur].idx = i;
			t[cur].leaf = true;
		} else {
			id[i] = t[cur].idx;
		}
		st[id[i]].insert(0);
	}

	t.process();

	while (m--) {
		int tt;
		cin >> tt;

		if (tt == 1) {
			int i, x;
			cin >> i >> x; --i;
			st[id[i]].erase(st[id[i]].find(sus[i]));
			sus[i] = x;
			st[id[i]].insert(sus[i]);
		} else {
			string q;
			cin >> q;

			int ans = -1;
			for (int i = 0, cur = 0; i < q.length(); i++) {
				cur = t[cur].next[q[i] - 'a'];
				int curr = cur;
				while (curr != -1) {
					if (t[curr].leaf) {
						int j = t[curr].idx;
						ans = max(ans, *st[j].rbegin());
					}
					curr = t[curr].exitLink;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
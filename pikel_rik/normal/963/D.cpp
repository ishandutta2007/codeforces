#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template <char f = 'a', size_t K = 26>
class AhoCorasick {
public:
	struct Node {
		bool leaf;
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
		for (const string& ss : s) {
			insert(ss);
		}
	}

	void insert(const string& s, int idx) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				t[cur].next[ch - f] = (int)t.size();
				t.emplace_back(cur, ch);
			}
			cur = t[cur].next[ch - f];
		}
		t[cur].idx = idx;
		t[cur].leaf = true;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.length();

	AhoCorasick<> t;
	int m;
	cin >> m;

	vector<pair<int, string>> queries(m);
	for (int i = 0; i < m; i++) {
		cin >> queries[i].first >> queries[i].second;
		t.insert(queries[i].second, i);
	}

	t.process();
	vector<int> ans(m, n + 1);
	vector<queue<int>> q(m);

	for (int i = 0, cur = 0; i < n; i++) {
		cur = t[cur].next[s[i] - 'a'];
		int curr = cur;
		while (curr != -1) {
			if (t[curr].idx != -1) {
				int j = t[curr].idx;
				if (q[j].size() == queries[j].first) {
					q[j].pop();
					q[j].push(i);
				} else {
					q[j].push(i);
				}
				if (q[j].size() == queries[j].first) {
					ans[j] = min(ans[j], q[j].back() - q[j].front() + (int)queries[j].second.length());
				}
			}
			curr = t[curr].exitLink;
		}
	}

	for (int i = 0; i < m; i++) {
		cout << (ans[i] < n + 1 ? ans[i] : -1) << '\n';
	}
	return 0;
}
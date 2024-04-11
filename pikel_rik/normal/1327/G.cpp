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
		bool leaf = false;
		ll val = 0;
		char pch;
		int p;
		int link = -1;
		int exitLink = -1;
		array<int, K> next;
		Node(int p = -1, char pch = '$') : p(p), pch(pch) {
			next.fill(-1);
		}
	};

	bool processed = false;
	vector<Node> t;
	AhoCorasick(): t(1) {}

	void insert(const string& s, int val) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				t[cur].next[ch - f] = (int)t.size();
				t.emplace_back(cur, ch);
			}
			cur = t[cur].next[ch - f];
		}
		t[cur].val += val;
		t[cur].leaf = true;
	}

	bool search(const string& s) const {
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
		if (processed) {
			return;
		}
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
			if (t[x].exitLink != -1) {
				t[x].val += t[t[x].exitLink].val;
			}

			for (int i = 0; i < K; i++) {
				if (t[x].next[i] == -1) {
					t[x].next[i] = x == 0 ? 0 : t[t[x].link].next[i];
				} else {
					q.push(t[x].next[i]);
				}
			}
		}
		processed = true;
	}

	Node& operator[](int i) {
		return t[i];
	}
};

int pos[16], c[1000];
string s, t[1000];

AhoCorasick<'a', 14> ac;
ll dp[1 << 14][1001];
pair<int, ll> nxt[16][1001];

pair<int, ll> next(int p, int cur) {
	if (nxt[p][cur].first != -1) {
		return nxt[p][cur];
	}

	int curr = cur;
	nxt[p][cur].second = ac[cur].val;
	for (int i = pos[p] + 1; i < pos[p + 1]; i++) {
		curr = ac[curr].next[s[i] - 'a'];
		nxt[p][cur].second += ac[curr].val;
	}
	if (pos[p + 1] != s.length()) {
		nxt[p][cur].first = curr;
	} else {
		nxt[p][cur].first = -2;
	}
	return nxt[p][cur];
}

ll recurse(int mask, int cur) {
	if (dp[mask][cur] != LLONG_MIN) {
		return dp[mask][cur];
	}
	auto p = next(14 - __builtin_popcount(mask), cur);
	if (p.first == -2) {
		return dp[mask][cur] = p.second;
	}
	for (int i = 0; i < 14; i++) {
		if (mask & (1 << i)) {
			dp[mask][cur] = max(dp[mask][cur], p.second + recurse(mask ^ (1 << i), ac[p.first].next[i]));
		}
	}
	return dp[mask][cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> t[i] >> c[i];
		ac.insert(t[i], c[i]);
	}
	ac.process();
	cin >> s;

	for (int i = 0; i < (1 << 14); i++) {
		for (int j = 0; j < ac.t.size(); j++) {
			dp[i][j] = LLONG_MIN;
		}
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 1000; j++) {
			nxt[i][j].first = -1;
		}
	}

	pos[0] = -1;
	int now = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '?') {
			pos[now++] = i;
		}
	}
	pos[now] = s.length();
	cout << recurse((1 << 14) - 1, 0) << '\n';
	return 0;
}
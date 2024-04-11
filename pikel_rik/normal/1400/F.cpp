#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1000 + 5;

string temp;
vector<string> bad;

bool isPrime(const string& s, int x) {
	int n = (int) s.length();
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += s[j] - '0';
			if (j - i + 1 != n && x % sum == 0) {
				return false;
			}
		}
	}
	return true;
}

void recurse(int x) {
	if (x == 0) {
		bad.push_back(temp);
	} else {
		for (int i = 2; i <= min(x, 9); i++) {
			temp += '0' + i;
			recurse(x - i);
			temp.pop_back();
		}
	}
}

template <char f = 'a', size_t K = 26>
class AhoCorasick {
public:
	struct Node {
		bool leaf;
		char pch;
		int p, link;
		array<int, K> next;
		Node(int p, char pch): leaf(false), p(p), pch(pch), link(-1) {
			next.fill(-1);
		}
	};

	vector<Node> t;
	AhoCorasick(): t(1, Node(-1, ' ')) {}

	AhoCorasick(const vector<string>& words): t(1, Node(-1, ' ')) {
		for (const string& s : words) {
			insert(s);
		}
	}

	void insert(const string& s) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				t[cur].next[ch - f] = (int)t.size();
				t.emplace_back(cur, ch);
			}
			cur = t[cur].next[ch - f];
		}
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

	int getLink(int cur) {
		if (t[cur].link == -1) {
			if (cur == 0 || t[cur].p == 0) {
				t[cur].link = 0;
			} else {
				t[cur].link = next(getLink(t[cur].p), t[cur].pch);
			}
		}
		return t[cur].link;
	}

	int next(int cur, char ch) {
		if (t[cur].next[ch - f] == -1) {
			if (cur == 0) {
				t[cur].next[ch - f] = 0;
			} else {
				t[cur].next[ch - f] = next(getLink(cur), ch);
			}
		}
		return t[cur].next[ch - f];
	}

	Node& operator[](int i) {
		return t[i];
	}
};

int n, x;
string s;
int dp[N][10*N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> x;
	n = (int) s.length();

	if (x == 1) {
		bad = {"1"};
	} else {
		recurse(x);
		bad.erase(remove_if(bad.begin(), bad.end(), [&](const string &ss) {
			return !isPrime(ss, x);
		}), bad.end());
	}

	AhoCorasick<'1', 9> t(bad);

	function<int(int, int)> recurse = [&] (int i, int cur) -> int {
		if (i == n) {
			return 0;
		}
		if (dp[i][cur] != -1) {
			return dp[i][cur];
		}
		if (t[t.next(cur, s[i])].leaf) {
			return dp[i][cur] = 1 + recurse(i + 1, cur);
		} else {
			return dp[i][cur] = min(1 + recurse(i + 1, cur), recurse(i + 1, t.next(cur, s[i])));
		}
	};
	memset(dp, -1, sizeof(dp));
	cout << recurse(0, 0) << '\n';
	return 0;
}
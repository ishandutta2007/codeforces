#include <bits/stdc++.h>
using namespace std;

template <char f = 'a', size_t K = 26>
struct trie {
	struct node {
		bool leaf;
		std::array<int, K> next;
		node() : leaf(false) {
			next.fill(-1);
		}
	};

	std::vector<node> t;

	trie() : t(1) {}

	void insert(const std::string &s) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				t[cur].next[ch - f] = (int) t.size();
				t.emplace_back();
			}
			cur = t[cur].next[ch - f];
		}
		t[cur].leaf = true;
	}

	bool search(const std::string &s) {
		int cur = 0;
		for (char ch : s) {
			if (t[cur].next[ch - f] == -1) {
				return false;
			}
			cur = t[cur].next[ch - f];
		}
		return t[cur].leaf;
	}

	node &operator[](int i) {
		return t[i];
	}
};

string to_string(int x, int bits) {
	string ans;
	for (int i = 0; i < bits; i++) {
		if (x & (1 << i)) {
			ans += '0';
		} else ans += '1';
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int lg = min(k, 32 - __builtin_clz(n - k + 1));

		vector<int> pref(n); pref[0] = s[0] == '0';
		for (int i = 1; i < n; i++) {
			pref[i] = (s[i] == '0') + pref[i - 1];
		}

		trie<'0', 2> t;
		for (int i = k - 1; i < n; i++) {
			//pref[i - lg] - pref[i - k]
			if ((i - lg < 0 ? 0 : pref[i - lg]) == (i - k < 0 ? 0 : pref[i - k])) {
				t.insert(s.substr(i - lg + 1, lg));
			}
		}

		string ans(k - lg, '0');
		for (int i = 0; i < (1 << lg); i++) {
			string now = to_string(i, lg);
			if (!t.search(now)) {
				for (char &ch : now) {
					ch = '0' + '1' - ch;
				}
				ans += now;
				break;
			}
		}
		if (ans.length() == k) {
			cout << "YES\n" << ans << '\n';
		} else cout << "NO\n";
	}
	return 0;
}
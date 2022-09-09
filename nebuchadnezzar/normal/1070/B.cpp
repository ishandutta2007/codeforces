#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

struct node {
	int l, r;
	bool fl0, fl1;
	uint addr;
	int mask;
	node() : l(-1), r(-1), fl0(false), fl1(false) {}
	int& go(int ind) {
		if (ind == 0) {
			return l;
		}
		return r;
	}
};

void solve() {
	int n;
	cin >> n;
	string tmp;
	getline(cin, tmp);
	vector<node> tree;
	tree.push_back(node());
	for (int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);
		int c = 0;
		int type = 0;
		if (s[0] == '+') {
			type = 1;
		}
		++c;
		uint addr = 0;
		for (int j = 0; j < 4; ++j) {
			int num = 0;
			while (c < szof(s) && s[c] != '.' && s[c] != '/') {
				num = num * 10 + s[c] - '0';
				++c;
			}
			addr = (addr << 8) | num;
			// cerr << num << endl;
			++c;
		}
		int mask = 32;
		if (c < szof(s)) {
			mask = 0;
			while (c < szof(s)) {
				mask = mask * 10 + s[c] - '0';
				++c;
			}
		}
		int cur = 0;
		for (int j = 0; j < mask; ++j) {
			int b = (addr >> (31 - j)) & 1;
			if (tree[cur].go(b) == -1) {
				tree[cur].go(b) = szof(tree);
				tree.push_back(node());
			}
			cur = tree[cur].go(b);
		}
		if (type == 0) {
			tree[cur].fl0 = true;
		} else {
			tree[cur].fl1 = true;
		}
		// for (int i = 31; i >= 0; --i) {
		// 	cerr << ((addr >> i) & 1);
		// }
		// cerr << endl;
	}

	vector<int> st;
	function<pair<int, pair<bool, bool>>(int, uint, int)> dfs = [&](int v, uint cur, int d) {
		tree[v].addr = cur << (32 - d);
		tree[v].mask = d;
		bool fl0 = false;
		bool fl1 = false;
		vector<int> arr;
		for (int i = 0; i < 2; ++i) {
			if (tree[v].go(i) != -1) {
				auto tmp = dfs(tree[v].go(i), (cur << 1) | i, d + 1);
				fl0 |= tmp.ss.ff;
				fl1 |= tmp.ss.ss;
				arr.push_back(tmp.ff);
			}
		}
		if ((fl0 && tree[v].fl1) || (fl1 && tree[v].fl0) || (tree[v].fl0 && tree[v].fl1)) {
			cout << "-1\n";
			exit(0);
		}
		fl0 |= tree[v].fl0;
		fl1 |= tree[v].fl1;
		int tmp = accumulate(arr.begin(), arr.end(), 0);
		if (!fl1) {
			for (int i = 0; i < tmp; ++i) {
				st.pop_back();
			}
			st.push_back(v);
			return make_pair(1, make_pair(fl0, fl1));
		}
		if (!fl0) {
			assert(tmp == 0);
			return make_pair(0, make_pair(fl0, fl1));
		}
		return make_pair(tmp, make_pair(fl0, fl1));
	};

	auto p = dfs(0, 0, 0);
	assert(szof(st) == p.ff);
	cout << p.ff << "\n";
	for (int v : st) {
		uint a = tree[v].addr >> 24;
		uint b = (tree[v].addr >> 16) & 255;
		uint c = (tree[v].addr >> 8) & 255;
		uint d = (tree[v].addr) & 255;
		cout << a << "." << b << "." << c << "." << d << "/" << tree[v].mask << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
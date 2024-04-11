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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<string> a, b;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a.push_back(s);
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		b.push_back(s);
	}

	bool found = false;
	string from = "", to = "";
	vector<pii> segs(n);
	vector<int> inter;

	for (int i = 0; i < n; ++i) {
		int l = INF, r = -INF;
		for (int j = 0; j < szof(a[i]); ++j) {
			if (a[i][j] != b[i][j]) {
				l = min(l, j);
				r = max(r, j);
			}
		}

		if (l <= r) {
			segs[i] = {l, r};
			inter.push_back(i);
			string cur_from = "";
			string cur_to = "";
			for (int j = l; j <= r; ++j) {
				cur_from += a[i][j];
				cur_to += b[i][j];
			}
			// cerr << i << " " << cur_from << " " << cur_to << endl;
			if (!found) {
				from = cur_from;
				to = cur_to;
				found = true;
			} else {
				if (from != cur_from || to != cur_to) {
					cout << "NO\n";
					return;
				}
			}
		}
	}

	if (!found) {
		cout << "YES\na\na\n";
		return;
	}

	string pref = "";
	while (true) {
		char from = 'z', to = 'a';
		for (int ind : inter) {
			if (segs[ind].ff == 0) {
				from = 'z';
				to = 'a';
				break;
			}
			from = min(from, a[ind][segs[ind].ff - 1]);
			to = max(to, a[ind][segs[ind].ff - 1]);
		}
		if (from != to) {
			break;
		}
		pref += a[inter[0]][segs[inter[0]].ff - 1];
		for (int ind : inter) {
			--segs[ind].ff;
		}
	}

	reverse(pref.begin(), pref.end());
	from = pref + from;
	to = pref + to;
	string suff = "";
	while (true) {
		char from = 'z', to = 'a';
		for (int ind : inter) {
			if (segs[ind].ss == szof(a[ind]) - 1) {
				from = 'z';
				to = 'a';
				break;
			}
			from = min(from, a[ind][segs[ind].ss + 1]);
			to = max(to, a[ind][segs[ind].ss + 1]);
		}
		if (from != to) {
			break;
		}
		suff += a[inter[0]][segs[inter[0]].ss + 1];
		for (int ind : inter) {
			++segs[ind].ss;
		}
	}

	from += suff;
	to += suff;

	string s = "";
	s += from;
	for (int i = 0; i < n; ++i) {
		s += "!";
		s += a[i];
	}
	vector<int> z(szof(s));
	int l = 0, r = 0;
	int cnt = -1;
	bool was = false;
	int last = 0;
	vector<int> pos(n, -1);
	for (int i = 1; i < szof(s); ++i) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < szof(s) && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
		if (s[i] == '!') {
			++cnt;
			last = i;
			was = false;
		}
		if (z[i] >= szof(from) && !was) {
			pos[cnt] = i - last - 1;
			was = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (pos[i] == -1) {
			continue;
		}
		string res = a[i];
		for (int j = 0; j < szof(from); ++j) {
			res[pos[i] + j] = to[j];
		}
		if (res != b[i]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	cout << from << "\n" << to << "\n";
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
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

bool term(char c) {
	return isalpha(c) || isdigit(c);
}

struct Message {
	string who;
	set<int> who_was;
	string msg;

	void read(const map<string, int>& id_name) {
		string str;
		getline(cin, str);

		forn(i, sz(str)) {
			if (str[i] == ':') {
				msg = str.substr(i + 1);
				break;
			} else {
				who += str[i];
			}
		}

		assert(!msg.empty());
		for (int i = 0; i < sz(msg); ) {
			if  (!term(msg[i])) {
				++i;
				continue;
			}
			string name;
			int j = i;
			while (j < sz(msg) && term(msg[j])) {
				name += msg[j];
				++j;
			}
			if  (id_name.count(name)) {
				who_was.insert(id_name.at(name));
			}
			i = j;
		}
	}
};

struct Solver {
	map<string, int> id_name;
	vector<string> names;
	int n, m;
	vector<Message> ms;

	bool read() {
		if  (scanf("%d\n", &n) < 1) {
			return 0;
		}
		forn(it, n) {
			string s;
			cin >> s;
			id_name[s] = it;
			names.pb(s);
			// cout << s << endl;
		}

		scanf("%d\n", &m);
		ms.resize(m);
		forn(i, m) {
			ms[i].read(id_name);
		}
		return 1;
	}

	void solve() {
		assert(read());

		vvi dp(m + 1, vi(n + 1, 0));
		vvi prev(m + 1, vi(n + 1, -1));

		dp[0][n] = 1;
		forn(i, m) forn(pr, n + 1) {
			if (!dp[i][pr]) {
				continue;
			}
			forn(cur, n) {
				if  (ms[i].who_was.count(cur) || cur == pr) {
					continue;
				}
				if  (ms[i].who != "?") {
					if  (id_name[ms[i].who] != cur) {
						continue;
					}
				}
				dp[i + 1][cur] = 1;
				prev[i + 1][cur] = pr;
			}
		}

		forn(last, n) {
			if  (dp[m][last]) {
				vi who;
				int cur = last;
				ford(it, m) {
					who.pb(cur);
					cur = prev[it + 1][cur];
				}
				reverse(all(who));
				forn(it, m) {
					cout << names[who[it]] << ":" << ms[it].msg << '\n';
				}
				return;
			}
		}

		puts("Impossible");
	}
};

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	int T;
	scanf("%d\n", &T);
	forn(t, T) {
		Solver().solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
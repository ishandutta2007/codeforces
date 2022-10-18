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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

int n;

struct Item {
	string name;
	int type;

	void read() {
		static char buf[20];
		scanf("%s %d\n", buf, &type);
		name = buf;
	}

	int to_int() const {
		// eprintf("name = %s\n", name.data());
		if  (name[0] == '0') {
			return -1;
		}
		int num = 0;
		for (char c : name) {
			if  (!isdigit(c)) {
				return -1;
			}
			num = num * 10 + (c - '0');
		}
		if  (num > n) {
			return -1;
		}
		return num;
	}

	bool operator < (const Item& it) const {
		return name < it.name;
	}

	void print() const {
		printf("%s %d\n", name.data(), type);
	}
};

vector<Item> items;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	items.resize(n);
	forn(i, n) {
		items[i].read();
	}
	return 1;
}

vector<pair<string, string>> ans;

vector<Item> rest;
int e;

string rand_name() {
	string ans;
	forn(i, 6) {
		ans += 'a' + (rand() % 26);
	}
	return ans;
}

void solve() {
	ans.clear();

	e = 0;
	for (const auto& it : items) {
		if  (it.type == 1) {
			++e;
		}
	}

	set<int> free_pref;
	set<int> free_suff;
	set<pair<int, Item>> pref0;
	set<pair<int, Item>> suff1;
	vector<Item> rest;

	for (int i = 1; i <= e; ++i) {
		free_pref.insert(i);
	}
	for (int i = e + 1; i <= n; ++i) {
		free_suff.insert(i);
	}

	for (const auto& it : items) {
		const int num = it.to_int();
		if  (num == -1) {
			rest.pb(it);
			continue;
		}
		if  (it.type == 1) {
			if  (num <= e) {
				free_pref.erase(num);
				continue;
			}
			assert(num >= e + 1 && num <= n);
			free_suff.erase(num);
			suff1.insert(mp(num, it));
		} else {
			if  (num >= e + 1) {
				assert(num <= n);
				free_suff.erase(num);
				continue;
			}
			free_pref.erase(num);
			pref0.insert(mp(num, it));
		}
	}

	while (!pref0.empty() || !suff1.empty()) {
		// {
		// 	eprintf("free_pref:\n");
		// 	for (int p : free_pref) {
		// 		eprintf("%d ", p);
		// 	}
		// 	eprintf("\n");

		// 	eprintf("free_suff:\n");
		// 	for (int p : free_suff) {
		// 		eprintf("%d ", p);
		// 	}
		// 	eprintf("\n");

		// 	eprintf("pref0:\n");
		// 	for (auto it : pref0) {
		// 		eprintf("%d: ", it.fst);
		// 		it.snd.print();
		// 	}
		// 	eprintf("\n");	

		// 	eprintf("suff1:\n");
		// 	for (auto it : suff1) {
		// 		eprintf("%d: ", it.fst);
		// 		it.snd.print();
		// 	}
		// 	eprintf("\n");			
		// }

		if  (!pref0.empty() && !free_suff.empty()) {
			auto it = *pref0.begin();
			pref0.erase(pref0.begin());

			free_pref.insert(it.fst);

			int pos = *free_suff.begin();
			free_suff.erase(pos);

			ans.pb(mp(it.snd.name, to_string(pos)));
			continue;
		}

		if  (!suff1.empty() && !free_pref.empty()) {
			auto it = *suff1.begin();
			suff1.erase(suff1.begin());

			free_suff.insert(it.fst);

			int pos = *free_pref.begin();
			free_pref.erase(pos);

			ans.pb(mp(it.snd.name, to_string(pos)));
			continue;
		}

		if  (!pref0.empty()) {
			auto it = *pref0.begin();
			pref0.erase(pref0.begin());
			free_pref.insert(it.fst);

			const string new_name = rand_name();
			ans.pb(mp(it.snd.name, new_name));
			it.snd.name = new_name;
			rest.pb(it.snd);
			continue;
		}

		assert(!suff1.empty());

		{
			auto it = *suff1.begin();
			suff1.erase(it);
			free_suff.insert(it.fst);

			const string new_name = rand_name();
			ans.pb(mp(it.snd.name, new_name));
			it.snd.name = new_name;
			rest.pb(it.snd);
		}
	}

	for (const auto& it : rest) {
		int pos = -1;
		if  (it.type == 1) {
			assert(!free_pref.empty());
			pos = *free_pref.begin();
			free_pref.erase(free_pref.begin());
		} else {
			assert(!free_suff.empty());
			pos = *free_suff.begin();
			free_suff.erase(free_suff.begin());
		}

		ans.pb(mp(it.name, to_string(pos)));
	}

	printf("%d\n", sz(ans));
	for (const auto& it : ans) {
		printf("move %s %s\n", it.fst.data(), it.snd.data());
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
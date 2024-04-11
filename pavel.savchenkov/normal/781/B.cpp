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

#define FILE_NAME "a"

const int MAXN = 5e3 + 10;

int n;
string name[MAXN];
string city[MAXN];

bool read() {
	if  (!(cin >> n)) {
		return 0;
	}
	forn(i, n) {
		cin >> name[i] >> city[i];
	}
	return 1;
}

int a[MAXN][2];
bool used[2 * MAXN];
string names[MAXN][2];
int who[MAXN];

map<string, int> num;

int get_num(const string& s) {
	if  (!num.count(s)) {
		int res = sz(num);
		num[s] = res;
	}
	return num[s];
}

void use(int i, int id) {
	who[i] = id;
	used[a[i][id]] = 1;
}

bool solve() {
	forn(i, n) {
		names[i][0] = name[i].substr(0, 3);
		a[i][0] = get_num(names[i][0]);
		names[i][1] = name[i].substr(0, 2) + city[i].substr(0, 1);
		a[i][1] = get_num(names[i][1]);
	}

	memset (used, 0, sizeof used);
	memset (who, -1, sizeof who);
	forn(i, n) forn(j, i) {
		if  (a[i][0] == a[j][0]) {
			use(i, 1);
			use(j, 1);
		}
	}

	while (1) {
		bool was = 0;
		forn(i, n) {
			if  (who[i] != -1) {
				continue;
			}
			forn(id, 2) {
				if  (used[a[i][id]]) {
					use(i, id ^ 1);
					was = 1;
					break;
				}
			}
		}
		if  (!was) {
			break;
		}
	}

	forn(i, n) {
		if  (who[i] == -1) {
			use(i, 0);
		}
	}

	forn(i, n) forn(j, i) {
		if  (a[i][who[i]] == a[j][who[j]]) {
			return 0;
		}
	}

	puts("YES");
	forn(i, n) {
		printf("%s\n", names[i][who[i]].data());
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		if  (!solve()) {
			puts("NO");
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
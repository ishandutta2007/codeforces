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

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	void change(int pos, int add) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += add;
		}
	}

	int sum(int r) {
		int res = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			res += t[i];
		}
		return res;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

struct Query {
	int type;
	int num;
	int time;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d%d", &type, &time, &num);
	}
};

int n;
vi ans;
vector<Query> qs;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	ans.assign(n, -1);
	qs.resize(n);
	forn(i, n) {
		qs[i].read(i);
	}
	return true;
}

void solve() {
	assert(read());

	sort(all(qs), [](const Query& q1, const Query& q2) { return q1.num < q2.num; });
	for (int i = 0, j = 0; i < n; i = j) {
		j = i;
		while (j < n && qs[j].num == qs[i].num) {
			++j;
		}

		vi ts;
		for (int k = i; k < j; ++k) {
			ts.pb(qs[k].time);
		}
		sort(all(ts));
		ts.resize(unique(all(ts)) - ts.begin());

		sort(qs.begin() + i, qs.begin() + j, [](const Query& q1, const Query& q2) { return q1.id < q2.id; });
	
		FenwTree T(sz(ts));
		for (int k = i; k < j; ++k) {
			int pos = lower_bound(all(ts), qs[k].time) - ts.begin();
			if  (qs[k].type == 1) {
				T.change(pos, +1);
			} else if  (qs[k].type == 2) {
				T.change(pos, -1);
			} else {
				assert(qs[k].type == 3);
				ans[qs[k].id] = T.sum(0, pos);
			}
		}
	}

	forn(i, n) {
		if  (ans[i] != -1) {
			printf("%d\n", ans[i]);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	solve();

	return 0;
}
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

struct Task {
	int a, t;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d", &a, &t);
	}

	bool operator < (const Task& other) const {
		return mp(t, id) < mp(other.t, other.id);
	}
};

int n, T;
vector<Task> tasks;

bool read() {
	if  (scanf("%d%d", &n, &T) < 2) {
		return 0;
	}
	tasks.resize(n);
	forn(i, n) {
		tasks[i].read(i);
	} 
	return 1;
}

int get(int real_ans) {
	sort(all(tasks), [&](const Task& t1, const Task& t2) { return t1.a > t2.a; });

	set<Task> alive;
	ll sum_alive = 0;
	auto add = [&](const Task& task, int k) {
		alive.insert(task);
		sum_alive += task.t;
		while  (sum_alive > T || sz(alive) > k) {
			sum_alive -= alive.rbegin()->t;
			alive.erase(*alive.rbegin());
		}
	};

	int ans = 0;
	for (int i = 0, j = 0; i < sz(tasks); i = j) {
		const int k = tasks[i].a;

		while (j < sz(tasks) && tasks[i].a == tasks[j].a) {
			add(tasks[j], k);
			++j;
		}

		if  (sz(alive) == real_ans) {
			vi ids;
			for (auto it : alive) {
				ids.pb(it.id);
			}
			printf("%d\n", sz(ids));
			printf("%d\n", sz(ids));
			for (int id : ids) {
				printf("%d ", id + 1);
			}
			printf("\n");
			return -1;
		} else {
			ans = max(ans, sz(alive));
		}
	}

	return ans;
}

void solve() {
	int ans = get(-1);
	get(ans);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();

		// break;
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
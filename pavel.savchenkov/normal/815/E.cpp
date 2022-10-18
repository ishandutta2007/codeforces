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
#define image(c) sort(all(c)), c.resize(unique(all(c)) - c.begin())

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


ll n, k;

bool read() {
	if  (scanf("%lld%lld", &n, &k) < 2) {
		return 0;
	}
	return 1;
}

vll generate(ll len) {
	vll res;
	set<ll> S;
	S.insert(len);
	while (!S.empty()) {
		ll cur = *S.rbegin();
		S.erase(cur);
		res.pb(cur);
	
		if  (!cur) {
			break;
		}

		S.insert((cur - 1) / 2);
		S.insert(cur / 2);
	}

	sort(all(res));
	image(res);
	return res;
}

vi left_len;
vi right_len;
vll lens;

vector<vll> dp;

ll get_cnt(int id, int min_left_len) {
	if  (left_len[id] == min_left_len) {
		return 1;
	}

	if  (left_len[id] < min_left_len) {
		return 0;
	}

	ll& ans = dp[id][min_left_len];
	if  (ans != -1) {
		return ans;
	}

	ans = 0;
	ans += get_cnt(left_len[id], min_left_len);
	ans += get_cnt(right_len[id], min_left_len);
	return ans;
}

ll get_mid_pos(int id, ll k, int min_left_len) {
	assert(k);
	assert(left_len[id] >= min_left_len);

	if  (left_len[id] == min_left_len) {
		return lens[min_left_len];
	}

	const ll left_cnt = get_cnt(left_len[id], min_left_len);
	if  (left_cnt >= k) {
		return get_mid_pos(left_len[id], k, min_left_len);
	}
	k -= left_cnt;
	return lens[left_len[id]] + 1 + get_mid_pos(right_len[id], k, min_left_len);
}

ll get_cnt2(int id) {
	if  (lens[id] == 0) {
		return 0;
	}
	if  (lens[id] == 1) {
		return 1;
	}
	if  (lens[id] == 2) {
		return 2;
	}

	ll& ans = dp[id][0];
	if  (ans != -1) {
		return ans;
	}

	ans = 0;
	ans += get_cnt2(left_len[id]);
	ans += get_cnt2(right_len[id]);
	return ans;
}

ll get_mid_pos2(int id, ll k) {
	assert(k);
	assert(lens[id] > 0);

	// printf("id=%d, k=%lld\n", id, k);

	if  (lens[id] == 1) {
		assert(k == 1);
		return 0;
	}

	if  (lens[id] == 2) {
		if  (k == 1) {
			return 0;
		}
		if  (k == 2) {
			return 1;
		}
		assert(0);
	}

	const ll left_cnt = get_cnt2(left_len[id]);
	if  (left_cnt >= k) {
		return get_mid_pos2(left_len[id], k);
	}
	k -= left_cnt;
	return lens[left_len[id]] + 1 + get_mid_pos2(right_len[id], k);
}

int get_pos_len(ll len) {
	const int pos = lower_bound(all(lens), len) - lens.begin();
	assert(pos < sz(lens) && lens[pos] == len);
	return pos;
}

ll solve() {
	if  (k == 1) {
		return 1;
	}
	if  (k == 2) {
		return n;
	}
	k -= 2;

	lens = generate(n - 2);
	left_len.resize(sz(lens));
	right_len.resize(sz(lens));
	forn(i, sz(lens)) {
		left_len[i] = get_pos_len((lens[i] - 1) / 2);
		right_len[i] = get_pos_len(lens[i] / 2);
	}

	// printf("lens:\n");
	// forn(i, sz(lens)) {
	// 	printf("%d: %lld (%d, %d)\n", i, lens[i], left_len[i], right_len[i]);
	// }

	dp.clear();
	dp.resize(sz(lens), vll(sz(lens), -1));

	vll coef(sz(lens), 0);
	coef.back() = 1;
	for (int i = sz(lens) - 1; i >= 0; ) {
		int j = i;
		while (j >= 0 && left_len[j] == left_len[i]) {
			--j;
		}

		ll sum_coef = 0;
		for (int z = j + 1; z <= i; ++z) {
			sum_coef += coef[z];
		}

		if  (lens[i] == 2) {
			ll pos = get_mid_pos2(sz(lens) - 1, k);
			return pos + 2;
		}

		if  (sum_coef < k) {
			k -= sum_coef;
			for (int z = j + 1; z <= i; ++z) {
				coef[left_len[z]] += coef[z];
				coef[right_len[z]] += coef[z];
				coef[z] = 0;
			}
			i = j;
			continue;
		}

		ll pos = get_mid_pos(sz(lens) - 1, k, left_len[i]);
		return pos + 2;
	}

	assert(0);
	return -1;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << "\n";
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int sum_prog(int l, int r, int k) {
	int tmp = mult(sum(l, r), k);
	if (tmp % 2 == 0) {
		tmp /= 2;
	} else {
		tmp += MOD;
		tmp /= 2;
	}
	return tmp;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<pii> rmq(bpv * 2);

	for (int i = 0; i < n; ++i) {
		rmq[i + bpv] = {inp[i], i};
	}

	for (int i = bpv - 1; i > 0; --i) {
		rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
	}

	function<pii(int, int, int, int, int)> get_max = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return make_pair(0, -1);
		}
		if (l <= vl && vr <= r) {
			return rmq[v];
		}
		int vm = (vl + vr) / 2;
		return max(get_max(v * 2, vl, vm, l, r), get_max(v * 2 + 1, vm, vr, l, r));
	};

	function<int(int, int)> rec = [&](int l, int r) {
		if (l >= r) {
			return 0;
		}
		if (l + k > r) {
			return 0;
		}

		int mem = get_max(1, 0, bpv, l, r).ss;

		int tmp = min(mem - l + 1, r - mem);
		int ret = 0;

		int from = 0;
		if (tmp >= k) {
			int q = (tmp - k) / (k - 1);
			while (k + (k - 1) * q <= tmp) {
				++q;
			}
			from = q;
			--q;

			add(ret, mult(inp[mem], sum_prog(k, k + (k - 1) * q, q + 1)));
		}

		int was = tmp;
		tmp = max(mem - l + 1, r - mem);
		if (tmp >= k) {
			int q = (tmp - k) / (k - 1);
			while (k + (k - 1) * q <= tmp) {
				++q;
			}
			--q;

			add(ret, mult(inp[mem], mult(was, q - from + 1)));
			from = q + 1;
		}		

		int to = (r - l - k) / (k - 1);
		while (k + (k - 1) * to <= r - l) {
			++to;
		}

		--to;

		add(ret, mult(inp[mem], sum_prog(r - l - (k + (k - 1) * from) + 1, r - l - (k + (k - 1) * to) + 1, to - from + 1)));

		add(ret, rec(l, mem));
		add(ret, rec(mem + 1, r));

		return ret;
	};

	int ans = rec(0, n);

	cout << ans << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}
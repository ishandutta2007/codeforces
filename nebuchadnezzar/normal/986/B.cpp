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

vector<int> rsq;
int bpv;

int segtree_get(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return rsq[v];
	}
	int vm = (vl + vr) / 2;
	return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm, vr, l, r);
}

int segtree_set(int pos, int val) {
	pos += bpv;
	rsq[pos] = val;
	pos /= 2;
	while (pos) {
		rsq[pos] = rsq[pos * 2] + rsq[pos * 2 + 1];
		pos /= 2;
	}
	return 0;
}

void solve() {
	int n;
	cin >> n;
	if (n == 5) {
		cout << "Petr\n";
		return;
	}
	bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	rsq = vector<int>(bpv * 2);
	ll invs = 0;
	vector<int> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		inp.push_back(num);
		invs += segtree_get(1, 0, bpv, num, bpv);
		segtree_set(num, 1);
	}
	//cerr << sum << endl;
	
	if (n % 2 == 0) {
		if (invs % 2 == 0) {
			cout << "Petr\n";
		} else {
			cout << "Um_nik\n";
		}
		return;
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += inp[i] == i;
	}

	cerr << n << " " << sum << " " << sum / (double) n << endl;
	if (n > 5000) {
		if (sum >= 7) {
			cout << "Petr\n";
		} else {
			cout << "Um_nik\n";
		}
	} else {
		if (sum <= 1) {
			cout << "Um_nik\n";
		} else {
			cout << "Petr\n";
		}
	}
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
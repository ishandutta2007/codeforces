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

struct value {
	int bc;
	int l;
	int na;
	value() {
		l = 0;
		bc = 0;
		na = 0;
	}
	value(char c) {
		l = 1;
		if (c == 'A') {
			bc = 0;
			na = 1;
		} else {
			bc = 1;
			na = 0;
		}
	}

	value operator+(value other) {
		value ret;
		ret.l = l + other.l;
		ret.bc = bc + other.bc;
		if (other.na == other.l) {
			ret.na = other.l + na;
		} else {
			ret.na = other.na;
		}
		return ret;
	}
};

int bpv;
vector<value> rsq;

value s_get(int v, int vl, int vr, int l, int r) {
	if (r <= vl || vr <= l) {
		return value();
	}
	if (l <= vl && vr <= r) {
		return rsq[v];
	}
	int vm = (vl + vr) / 2;
	return s_get(v * 2, vl, vm, l, r) + s_get(v * 2 + 1, vm, vr, l, r);
}

void solve() {
	string s;
	cin >> s;
	string t;
	cin >> t;
	string tot = s + t;
	bpv = 1;
	while (bpv < szof(tot)) {
		bpv *= 2;
	}

	rsq = vector<value>(bpv * 2);
	for (int i = 0; i < szof(tot); ++i) {
		rsq[i + bpv] = value(tot[i]);
	}
	for (int i = bpv - 1; i; --i) {
		rsq[i] = rsq[i * 2] + rsq[i * 2 + 1];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		--l1; --l2;
		auto v1 = s_get(1, 0, bpv, l1, r1);
		auto v2 = s_get(1, 0, bpv, l2 + szof(s), r2 + szof(s));

		if (v1.bc % 2 != v2.bc % 2 || v1.bc > v2.bc) {
			cout << "0";
			continue;
		}

		if (v1.na < v2.na) {
			cout << "0";
			continue;
		}

		if (v1.bc == 0 && v2.bc && v1.na == v2.na) {
		 	cout << "0";
		 	continue;
		}

		int tmp = (v1.na - v2.na) % 3;
		if (tmp != 0 && v2.bc - v1.bc == 0) {
			cout << "0";
			continue;
		}
		cout << "1";
	}
	cout << "\n";
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
#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int bdv = 1;

vector<int> rsq;

int segtree_set(int pos, int val) {
 	pos += bdv;
 	rsq[pos] = val;
 	pos /= 2;
 	while (pos) {
 	 	rsq[pos] = rsq[pos * 2] + rsq[pos * 2 + 1];
 	 	pos /= 2;
 	}
 	return 0;
}

int segtree_get(int v, int vl, int vr, int l, int r) {
 	if (vr < l || r < vl) {
 	 	return 0;
 	}
 	if (l <= vl && vr <= r) {
 	 	return rsq[v];
 	}
 	int vm = (vl + vr) / 2;
 	return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm + 1, vr, l, r);
}

int n;
map<int, vector<tuple<int, int, int>>> inp;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	int num_q = 0;
	for (int i = 0; i < n; ++i) {
	 	int a, t, x;
	 	scanf("%d%d%d", &a, &t, &x);
	 	inp[x].puba(make_tuple(a, t, num_q));
	 	if (a == 3) {
			++num_q;
	 	}
	}

	vector<int> ans(num_q);

	for (auto& p: inp) {
	 	//int x = p.ff;
	 	//cerr << "new number " << p.ff << endl;
	 	bdv = 1;
	 	while (bdv < szof(p.ss)) {
	 	 	bdv *= 2;
	 	}
	 	rsq.resize(bdv * 2);
	 	fill(bend(rsq), 0);
	 	vector<int> times;
	 	for (auto& t: p.ss) {
	 	 	times.puba(get<1>(t));
	 	}
	 	sort(bend(times));
	 	for (auto& t: p.ss) {
	 	 	int a, ti, i;
	 	 	tie(a, ti, i) = t;
	 	 	int tpos = lower_bound(bend(times), ti) - times.begin();
	 	 	//cerr << a << " " << ti << " " << i << endl;
	 	 	//cerr << tpos << endl;
			if (a == 1) {
			 	segtree_set(tpos, 1);
			} else if (a == 2) {
			 	segtree_set(tpos, -1);
			} else {
			 	ans[i] = segtree_get(1, 0, bdv - 1, 0, tpos);
			}
	 	}
	}

	for (int num: ans) {
	 	cout << num << "\n";
	}

	return 0;
}
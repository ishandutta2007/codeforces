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
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
const int bd = 20, bdv = 1 << bd;

int n;
int arr[MAXN];
ll rsq[bdv * 2], here[bdv * 2];
vector<ll> arry;

int segtree_segplus(int v, int vl, int vr, int l, int r, ll val);

int segtree_pushdown(int v, int vl, int vr) {
	/*
	if (!here[v]) {
	 	return 0;
	}
	int vm = (vl + vr) / 2;
	segtree_segplus(v * 2, vl, vm, vl, vm, here[v]);
	segtree_segplus(v * 2 + 1, vm + 1, vr, vm + 1, vr, here[v]);*/

	int vm = (vl + vr) / 2;
	rsq[v * 2] = (rsq[v * 2] + (ll) (arry[vm + 1] - arry[vl]) * here[v]) % MOD;
	rsq[v * 2 + 1] = (rsq[v * 2 + 1] + (ll) (arry[vr + 1] - arry[vm + 1]) * here[v]) % MOD;
	here[v * 2] = (here[v * 2] + here[v]) % MOD;
	here[v * 2 + 1] = (here[v * 2 + 1] + here[v]) % MOD;

	here[v] = 0;
	return 0;
}

int segtree_segplus(int v, int vl, int vr, int l, int r, ll val) {
 	if (vr < l || r < vl) {
 	 	return 0;
 	}
 	if (l <= vl && vr <= r) {
 	 	rsq[v] = (rsq[v] + (ll) (arry[vr + 1] - arry[vl]) * val) % MOD;
 	 	here[v] = (here[v] + val) % MOD;
 	 	return 0;
 	}

 	segtree_pushdown(v, vl, vr);

 	int vm = (vl + vr) / 2;
 	segtree_segplus(v * 2, vl, vm, l, r, val);
 	segtree_segplus(v * 2 + 1, vm + 1, vr, l, r, val);
 	rsq[v] = (rsq[v * 2] + rsq[v * 2 + 1]) % MOD;
 	return 0;
}

ll segtree_get(int v, int vl, int vr, int l, int r) {
 	if (vr < l || r < vl) {
 	 	return 0;
 	}
 	if (l <= vl && vr <= r) {
 	 	return rsq[v];
 	}

 	segtree_pushdown(v, vl, vr);

 	int vm = (vl + vr) / 2;
 	return (segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm + 1, vr, l, r)) % MOD;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	scanf("%d", &n);
	arry.puba(1);

	for (int i = 0; i < n; ++i) {
	 	scanf("%d", arr + i);
	 	arry.puba(arr[i]);
	}

	sort(bend(arry));
	arry.resize(unique(bend(arry)) - arry.begin());
	/*
	while (szof(arry) <= bdv) {
	 	arry.puba(arry.back());
	}*/
	ll ans = 0;

	vector<pair<pii, ll>> have;

	for (int i = 0; i < n; ++i) {
	 	int prev = 0;
	 	if (i) {
	 	 	prev = arr[i - 1];
	 	}
	 	int pos = lower_bound(bend(arry), min(arr[i], prev)) - arry.begin();
	 	//ll tmp = segtree_get(1, 0, bdv - 1, 0, pos - 1);
	 	ll tmp = 0;

	 	while (szof(have)) {
	 	 	//segtree_segplus(1, 0, bdv - 1, have.back().ff.ff, have.back().ff.ss, -have.back().ss);
	 	 	tmp = (tmp + (ll) (arry[min(pos, have.back().ff.ss)] - arry[have.back().ff.ff]) * have.back().ss) % MOD;
	 	 	have.pop_back();
	 	}

		//segtree_segplus(1, 0, bdv - 1, 0, pos - 1, tmp);
		have.puba({{0, pos}, tmp});
		ans = (ans + (arry[pos] - arry[0]) * tmp) % MOD;
		pos = lower_bound(bend(arry), arr[i]) - arry.begin();
		//segtree_segplus(1, 0, bdv - 1, 0, pos - 1, 1);
		have.puba({{0, pos}, 1});
		ans = (ans + (arry[pos] - arry[0])) % MOD;
	}

	if (ans < 0) {
	 	ans += MOD;
	}

	cout << ans << "\n";

	return 0;
}
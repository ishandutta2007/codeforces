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
const int MAXN = 2e5 + 5, bd = 18, bdv = 1 << bd;

int n, k, a, b, q;
int rsq[2][bdv * 2];

int segtree_plus(int pos, int val) {
 	pos += bdv;
 	rsq[0][pos] += val;
 	rsq[0][pos] = min(rsq[0][pos], a);
	rsq[1][pos] += val;
 	rsq[1][pos] = min(rsq[1][pos], b);

 	pos /= 2;
 	while (pos) {
 	 	rsq[0][pos] = rsq[0][pos * 2] + rsq[0][pos * 2 + 1];
 	 	rsq[1][pos] = rsq[1][pos * 2] + rsq[1][pos * 2 + 1];
 	 	pos /= 2;
 	}
 	return 0;
}

int segtree_sum(int num, int v, int vl, int vr, int l, int r) {
 	if (vr < l || r < vl) {
 	 	return 0;
 	}
 	if (l <= vl && vr <= r) {
 	 	return rsq[num][v];
 	}
 	int vm = (vl + vr) / 2;
 	return segtree_sum(num, v * 2, vl, vm, l, r) + segtree_sum(num, v * 2 + 1, vm + 1, vr, l, r);
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);

	for (int i = 0; i < q; ++i) {
	 	int t;
	 	scanf("%d", &t);
	 	if (t == 1) {
	 	 	int di, ai;
	 	 	scanf("%d%d", &di, &ai);
	 	 	--di;
	 	 	segtree_plus(di, ai);
	 	} else {
	 	 	int pi;
	 	 	scanf("%d", &pi);
	 	 	--pi;
	 	 	//cerr << segtree_sum(0, 1, 0, bdv - 1, pi + k, bdv - 1) << " " << segtree_sum(1, 1, 0, bdv - 1, 0, pi - 1) << endl;
			cout << segtree_sum(0, 1, 0, bdv - 1, pi + k, bdv - 1) + segtree_sum(1, 1, 0, bdv - 1, 0, pi - 1) << "\n";
	 	}
	}

	return 0;
}
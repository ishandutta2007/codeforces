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
const int MAXN = 2e5 + 5;
const int bd = 18, bdv = 1 << bd;

int n;
vector<int> where[MAXN];

ll rsq[bdv * 2];
int rmq[bdv * 2];
int there[bdv * 2];

int segtree_pushdown(int v, int vl, int vr) {
 	if (there[v] == -1) {
 	 	return 0;
 	}
 	int tmp = there[v];
 	there[v * 2] = tmp;
 	there[v * 2 + 1] = tmp;
	rsq[v * 2] = (ll) tmp * (vr - vl + 1) / 2;
	rsq[v * 2 + 1] = rsq[v * 2];
	rmq[v * 2] = tmp;
	rmq[v * 2 + 1] = tmp;
	there[v] = -1;
	return 0;
}

int segtree_set(int v, int vl, int vr, int l, int r, int val) {
 	if (vr < l || r < vl) {
 	 	return 0;
 	}
 	if (l <= vl && vr <= r) {
     	there[v] = val;
     	rsq[v] = (ll) val * (vr - vl + 1);
     	rmq[v] = val;
     	return 0;
    }

    segtree_pushdown(v, vl, vr);

    int vm = (vl + vr) / 2;
	segtree_set(v * 2, vl, vm, l, r, val);
	segtree_set(v * 2 + 1, vm + 1, vr, l, r, val);
	rsq[v] = rsq[v * 2] + rsq[v * 2 + 1];
	rmq[v] = min(rmq[v * 2], rmq[v * 2 + 1]);
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
 	return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm + 1, vr, l, r);
}

int segtree_find(int v, int vl, int vr, int val) {
 	if (vl == vr) {
 	 	if (rmq[v] <= val) {
 	 	 	return vl;
 	 	}
 	 	return vl - 1;
 	}
 	if (rmq[v] > val) {
 		return vl - 1;
 	}
 	int vm = (vl + vr) / 2;
 	int tmp = segtree_find(v * 2 + 1, vm + 1, vr, val);
 	if (tmp > vm) {
 	 	return tmp;
 	}
 	return segtree_find(v * 2, vl, vm, val);
}

int main() {
	memset(there, -1, sizeof there);
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	for (int j = 1; j * j <= num; ++j) {
	 	 	if (num % j == 0) {
	 	 	 	where[j].puba(i);
	 	 	 	if (num / j != j) {
	 	 	 	 	where[num / j].puba(i);
	 	 	 	}
	 	 	}
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	rsq[i + bdv] = i - 1;
	 	rmq[i + bdv] = i - 1;
	}

	for (int i = n; i < bdv; ++i) {
	 	rmq[i + bdv] = MAXN;
	}

	for (int i = bdv - 1; i > 0; --i) {
	 	rsq[i] = rsq[i * 2] + rsq[i * 2 + 1];
	 	rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);
	}

	ll ans = 0;
	for (int i = MAXN - 1; i > 0; --i) {
	 	if (szof(where[i]) <= 1) {
	 	 	continue;
	 	}
	 	/*
	 	cerr << i << endl;
	 	for (int pos: where[i]) {
	 	 	cerr << pos << " ";
	 	}
	 	cerr << endl;*/
	 	int sz = szof(where[i]);
  		int prel = where[i][sz - 2];
  		int last = where[i][sz - 1];
  		int beg = where[i][0];
  		int sec = where[i][1];

  		ll tmp = 0;

  		//cerr << beg << " " << sec << " " << prel << " " << last << endl;
  		int g = min(prel - 1, segtree_find(1, 0, bdv - 1, prel - 1));
  	 	if (g >= 0) {
  	 		tmp = (ll) (prel - 1) * (g + 1) - segtree_get(1, 0, bdv - 1, 0, g);
  	 	}
  	 	//cerr << tmp << endl;
  	 	segtree_set(1, 0, bdv - 1, 0, g, prel - 1);
  	 	
  	 	
  	 	g = min(segtree_find(1, 0, bdv - 1, last - 1), last - 1);
  	 	if (g > beg) {
  	 		tmp += (ll) (last - 1) * (g - beg) - segtree_get(1, 0, bdv - 1, beg + 1, g);
  	 	}
		//cerr << tmp << endl;
		segtree_set(1, 0, bdv - 1, beg + 1, g, last - 1);
  	 	
  	 	if (n - 1 > sec) {
  	 		tmp += (ll) (n - 1) * (n - 1 - sec) - segtree_get(1, 0, bdv - 1, sec + 1, n - 1);
  	 	}
		//cerr << tmp << endl;
		segtree_set(1, 0, bdv - 1, sec + 1, n - 1, n - 1);
  	 	ans += tmp * i;
  	 	//cerr << ans << endl;
	}

	cout << ans << "\n";

	return 0;
}
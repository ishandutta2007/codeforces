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
const int bd = 18, bdv = 1 << bd;

int n;
bool cmp(pii p1, pii p2) {
 	return (ll) p1.ff * p2.ss > (ll) p2.ff * p1.ss;
}

double rmq[bdv * 2];

int segtree_set(int pos, double val) {
 	pos += bdv;
 	rmq[pos] = max(rmq[pos], val);
 	pos /= 2;
 	while (pos) {
 	 	rmq[pos] = max(rmq[pos * 2], rmq[pos * 2 + 1]);
 	 	pos /= 2;
 	}
 	return 0;
}

double segtree_get(int v, int vl, int vr, int l, int r) {
 	if (vr < l || r < vl) {
 	 	return 0;
 	}
 	if (l <= vl && vr <= r) {
 	 	return rmq[v];
 	}
	int vm = (vl + vr) / 2;
	return max(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm + 1, vr, l, r));
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	vector<pii> inp;
	vector<int> arrp;
	ll sumt = 0;
	for (int i = 0; i < n; ++i) {
	 	int p;
	 	scanf("%d", &p);
	 	inp.puba({p, -1});
	 	arrp.puba(p);
	}

	sort(bend(arrp));
	arrp.resize(unique(bend(arrp)) - arrp.begin());

	for (int i = 0; i < n; ++i) {
	 	int t;
	 	scanf("%d", &t);
	 	inp[i].ss = t;
	 	sumt += t;
	}

	sort(bend(inp), cmp);

	double l = 0, r = 1;

	for (int q = 0; q < 50; ++q) {
    	double mid = (l + r) / 2;
    	ll t = 0;
    	bool flag = true;
    	memset(rmq, 0, sizeof rmq);

    	for (int i = 0; i < n; ++i) {
    		int c = i;
    		ll heret = 0;
    		while (c < n && (ll) inp[c].ff * inp[i].ss == (ll) inp[i].ff * inp[c].ss) {
    		 	heret += inp[c].ss;
    		 	int pos = lower_bound(bend(arrp), inp[c].ff) - arrp.begin();
    		 	segtree_set(pos, inp[c].ff * (1 - mid * (t + inp[c].ss) / sumt));
    		 	//cerr << pos << " " << inp[c].ff * (1 - mid * (t + inp[c].ss) / sumt) << endl;
    		 	++c;
    		}

    		for (int j = i; j < c; ++j) {
	    		int pos = lower_bound(bend(arrp), inp[j].ff) - arrp.begin();
	    		//cerr << segtree_get(1, 0, bdv - 1, 0, pos - 1) << endl;
    		 	if (segtree_get(1, 0, bdv - 1, 0, pos - 1) > inp[j].ff * (1 - mid * (t + heret) / sumt)) {
    		 	 	flag = false;
    		 	 	break;
    		 	}
    		}
	
	        if (!flag) {
	         	break;
	        }

	        t += heret;
    		i = c - 1;
    	}
    	if (flag) {
    	 	l = mid;
    	} else {
    	 	r = mid;
    	}
	}

	printf("%.10f\n", l);

	return 0;
}
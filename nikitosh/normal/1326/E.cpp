#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define FNAME ""

const int N = 3e5 + 5, INF = 1e9;

int q[N], t[4 * N], toPush[4 * N];
pii p[N];

void push(int v, int vl, int vr) {
	if (vl != vr - 1)
		forn (j, 2)
			toPush[2 * v + j] += toPush[v];
	t[v] += toPush[v];
	toPush[v] = 0;
}

// find position >= pos with val <= x
int nextGreaterX(int v, int vl, int vr, int pos, int x) {
	push(v, vl, vr);
	if (vr <= pos || t[v] > x) return INF;
	if (vr - vl == 1) return vl;
	int vm = (vl + vr) / 2;
	int ans = nextGreaterX(2 * v, vl, vm, pos, x);
	if (ans == INF)
		ans = nextGreaterX(2 * v + 1, vm, vr, pos, x);
	return ans;
}

void update(int v, int vl, int vr, int l, int r, int dlt) {
	if (vl >= l && vr <= r) {
		toPush[v] += dlt;
		push(v, vl, vr);
		return;
	}
	push(v, vl, vr);
	if (vl >= r || l >= vr)
		return;
	int vm = (vl + vr) / 2;
	update(2 * v, vl, vm, l, r, dlt);
	update(2 * v + 1, vm, vr, l, r, dlt);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int vl, int vr, int ind) {
	push(v, vl, vr);
	if (vr - vl == 1)
		return t[v];
	int vm = (vl + vr) / 2;
	if (ind < vm)
		return get(2 * v, vl, vm, ind);
	return get(2 * v + 1, vm, vr, ind);
}
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	forn (i, n) {
		cin >> p[i].fst;
		p[i].snd = i;
	}
	sort(p, p + n);
	reverse(p, p + n);
	
	forn (i, n) {
		cin >> q[i];
	}
	
	int tSize = 1;
	while (tSize <= n)
		tSize *= 2;
	t[tSize + n] = -1;
	fornr (i, tSize)
		t[i] = min(t[2 * i], t[2 * i + 1]);
	int it = 0;
	forn (i, n) {
		while (get(1, 0, tSize, n - 1) == 0) {
			int ind = p[it++].snd;
			int r = nextGreaterX(1, 0, tSize, ind, -1);
			r = min(r, n);
			if (r == n)
				r--;
			update(1, 0, tSize, ind, r + 1, 1);
		} 
		cout << p[it - 1].fst << " ";
		
		int r = nextGreaterX(1, 0, tSize, q[i] - 1, 0);
		r = min(r, n);
		if (r == n)
			r--;
		update(1, 0, tSize, q[i] - 1, r + 1, -1);
	}
	
	return 0;
}
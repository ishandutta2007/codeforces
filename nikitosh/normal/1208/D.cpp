#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 2e5 + 5;

ll a[MAX_N], b[MAX_N], t[MAX_N * 4], toPush[MAX_N * 4];
int ans[MAX_N];

void push(int v, int vl, int vr) {
 	if (vl != vr - 1)
 		forn (j, 2)
 			toPush[2 * v + j] += toPush[v];
 	t[v] += toPush[v];
 	toPush[v] = 0;
}

int go(int v, int vl, int vr, ll val) {
	push(v, vl, vr);
 	if (vl == vr - 1)
 		return v;
 	int vm = (vl + vr) / 2;
 	if (t[2 * v] + toPush[2 * v] >= val)
 	 	return go(2 * v, vl, vm, val);
 	return go(2 * v + 1, vm, vr, val);
}

void update(int v, int vl, int vr, int l, int r, ll value) {
	if (vl >= l && vr <= r) {
 		toPush[v] += value;
 		push(v, vl, vr);
 		return;
 	}
 	push(v, vl, vr);
 	if (vl >= r || l >= vr)
 		return;
 	int vm = (vl + vr) / 2;
 	update(2 * v, vl, vm, l, r, value);
 	update(2 * v + 1, vm, vr, l, r, value);
 	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		cin >> a[i];
	b[0] = 0;
	forab (i, 1, n)
		b[i] = b[i - 1] + i;
	int tSize = 1;
	while (tSize < n)
		tSize *= 2;	
	forn (i, n)
		t[tSize + i] = b[i];
	forab (i, n, tSize)
		t[tSize + i] = -1;
	for (int i = tSize - 1; i > 0; i--)
		t[i] = max(t[2 * i], t[2 * i + 1]);
	fornr (i, n) {
		int k = go(1, 0, tSize, a[i]) - tSize;
		ans[i] = k + 1;
		update(1, 0, tSize, k + 1, n, -(k + 1));
		update(1, 0, tSize, k, k + 1, -a[i] - 1);	 	
	}
	forn (i, n)
		printf("%d ", ans[i]);
	return 0;
}
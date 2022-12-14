#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int K = 150;
const int INF = 1e9 + 7;
const int MAX = (1 << 30);

int a[N], ans[M], f[4 * N], psh[4 * N], treeSize;
vector<pii> q[N];

void push(int v, int vl, int vr) {
	f[v] = min(f[v], psh[v]);
	if (vl == vr - 1) {
		return;
	}
	forn(j, 2)
		psh[2 * v + j] = min(psh[2 * v + j], psh[v]);
		
	psh[v] = INF;
}

void update(int v, int vl, int vr, int l, int r, int mn) {
	if (vr <= l || r <= vl) {
		return;
	}
	if (l <= vl && vr <= r) {
		psh[v] = min(psh[v], mn);
		push(v, vl, vr);
		return;
	}
	push(v, vl, vr);
	update(2 * v, vl, (vl + vr) / 2, l, r, mn);
	update(2 * v + 1, (vl + vr) / 2, vr, l, r, mn);
	f[v] = min(f[2 * v], f[2 * v + 1]);
}

int get(int v, int vl, int vr, int ind) {
	if (vr <= ind || ind < vl) {
		return INF;
	}
	push(v, vl, vr);
	if (ind <= vl && vr <= ind + 1) {
		return f[v];
	}
	return min(get(2 * v, vl, (vl + vr) / 2, ind), get(2 * v + 1, (vl + vr) / 2, vr, ind));
}


struct Node {
	int x;
	Node *vl, *vr;
	Node(int xx): x(xx), vl(NULL), vr(NULL) {}
};


int get_pos(Node* v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return -1;
	}
	if (l <= vl && vr <= r) {
		return v->x;
	}
	int cur = -1;
	if (v->vl)
		cur = max(cur, get_pos(v->vl, vl, (vl + vr) / 2, l, r)); 
		
	if (v->vr)
		cur = max(cur, get_pos(v->vr, (vl + vr) / 2, vr, l, r));
	return cur;
}

void update_pos(Node* v, int vl, int vr, int ind, int x) {
	v->x = max(v->x, x);
	if (vl == vr - 1) {
		return;	
	}
	int mid = (vl + vr) / 2;
	if (ind < mid) {
		if (!v->vl) {
			v->vl = new Node(x);
		}
		update_pos(v->vl, vl, mid, ind, x);
	} else {
		if (!v->vr) {
			v->vr = new Node(x);
		}
		update_pos(v->vr, mid, vr, ind, x);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	forn(i, 4 * N) {
		f[i] = INF;
		psh[i] = INF;
	}
	
	int n;
	cin >> n;
	forn(i, n) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	forn(i, m) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		q[r].pb(mp(l, i));
	}
	treeSize = 1;
	while(treeSize < n) {
		treeSize *= 2;
	}
	Node *root = new Node(-1);
	update_pos(root, 0, MAX, a[0], 0);
	forab(i, 1, n) {
		int left = i - 1;
		int diff = abs(a[i] - a[i - 1]);
		do {
			update(1, 0, treeSize, 0, left + 1, diff);
			left = get_pos(root, 0, MAX, a[i] - diff + 1, a[i] + diff);
			if (left != -1)
				diff = min(abs(a[i] - a[left]), get(1, 0, treeSize, left));
		} while(left != -1);
		update_pos(root, 0, MAX, a[i], i);
		for(pii p: q[i]) {
			int lf = p.fst, ind = p.snd;
			ans[ind] = get(1, 0, treeSize, lf);
		}
	}
	forn(i, m) {
		cout << ans[i] << '\n';
	}
}
#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 2e5 + 7, vmx = 2e5 + 3;
int n, m, x, a[N], b[N];

template < int N > struct St { 
	int w[N], f[(int) log2(N) + 2][N], lg[N], op;
	inline int getv (int x, int y) { return op ? (w[x] < w[y] ? x : y) : (w[x] > w[y] ? x : y); }
	void init (int *a, int n, bool opr = false) { // op = 0 : max; || op = 1 : min
		op = opr; 
		L(i, 2, n) lg[i] = lg[i >> 1] + 1;
		L(i, 1, n) w[i] = a[i], f[0][i] = i;
		L(i, 1, lg[n]) L(j, 1, n - (1 << i) + 1) f[i][j] = getv(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);		
	}
	inline int query (int l, int r) {
		int p = lg[r - l + 1];
		return getv (f[p][l], f[p][r - (1 << p) + 1]);
	}
};

int val[N * 60], ch[N * 60][2], rt[N], tot;
void add (int ls, int &x, int L, int R, int p, int w) {
	x = ++tot, val[x] = val[ls] + w, ch[x][0] = ch[ls][0], ch[x][1] = ch[ls][1];
	if(L == R) return ;
	int mid = (L + R) >> 1;
	if(p <= mid) add (ch[ls][0], ch[x][0], L, mid, p, w);
	else add (ch[ls][1], ch[x][1], mid + 1, R, p, w);
}
int query (int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return val[x];
	int mid = (L + R) >> 1, res = 0;
	if(l <= mid) res += query (ch[x][0], L, mid, l, r);
	if(r > mid) res += query (ch[x][1], mid + 1, R, l, r);
	return res;
}

St < N > Mn, Mx;
vi c[N];
ll ns;

void divide (int l, int r) {
	if(l > r) return ;
	int p = Mn.query (l, r), ls = 0;
	if(l != 1) ls = max(ls, x - (l < p ? b[Mx.query(l, p - 1)] : -vmx)); 
	if(r != m) ls = max(ls, x - (p < r ? b[Mx.query(p + 1, r)] : -vmx)); 
	if(b[p] <= x && ls < vmx) 
		ns += query (rt[x - b[p]], 0, vmx, ls + 1, vmx);
	divide (l, p - 1), divide(p + 1, r);
}

int f[N];
bool vis[N];
int find (int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge (int x, int y) {
	x = find(x), y = find(y);
	if(a[x] > a[y]) swap(x, y);
	f[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;
	L(i, 1, n) cin >> a[i], c[a[i]].push_back(i);
	L(i, 1, n) f[i] = i;
	L(i, 0, x) {
		if(i) rt[i] = rt[i - 1];
		for(const int & v : c[i]) {
			if(vis[v - 1]) add (rt[i], rt[i], 0, vmx, a[find(v - 1)], -1), merge (v, v - 1);
			if(vis[v + 1]) add (rt[i], rt[i], 0, vmx, a[find(v + 1)], -1), merge (v, v + 1);
			add (rt[i], rt[i], 0, vmx, a[find(v)], 1);
			vis[v] = true;
		}
	} 
	L(i, 1, m) cin >> b[i];
	Mx.init (b, m, false), Mn.init (b, m, true);
	divide (1, m);
	cout << ns << "\n";
	return 0; 
}
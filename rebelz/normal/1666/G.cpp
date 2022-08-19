// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 4e5 + 5;

const long double eps = 1e-4;

struct Point{ long double x, y, z; } A[N];
Point inline cross(Point a, Point b) {	return (Point) { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x }; }
Point operator - (Point a, Point b) { return (Point) { a.x - b.x, a.y - b.y, a.z - b.z }; }
Point operator + (Point a, Point b) { return (Point) { a.x + b.x, a.y + b.y, a.z + b.z }; }

long double inline dot(Point a, Point b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
long double inline len(Point a) { return sqrt(dot(a, a)); }
long double inline randEps() { return (rand() / RAND_MAX - 0.5) * eps; }

int inline cmp(long double x, long double y) {
	if (fabs(x - y) < eps) return 0;
	return x < y ? -1 : 1;
}

int n, m, q, sz[N];
long double ans[N];

bool fk[N];

typedef long double db;

long double area(Point a, Point b, Point c) {
	return len(cross(b - a, c - a)) / 2;
}

struct Ins{
	int x;
	long double z;
	Point w;
	bool operator < (const Ins &b) const {
		return cmp(z, b.z) == -1;
	}
} e[N << 2];

struct Mg{
	int x, y;
	long double z;
	bool operator < (const Mg &b) const {
		return z < b.z;
	}
} h[N << 2];

int le;

void inline Add(int x, int y) {
	h[++le] = (Mg) { x, y, min(A[x].z, A[y].z) };
}

struct Qu{
	int h, p, id;
	bool operator < (const Qu &b) const {
		return h < b.h; 
	}
} Q[N];
int t;

long double aaa = 0;

Point g[N];

int f[N], tot;

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	f[x] = y; sz[y] += sz[x];
	g[y] = g[y] + g[x];
}

void inline add(int p, long double l, long double r, Point w) {
	e[++tot] = (Ins) { p, r, w };
//	cout << l << " " << r << "??" << p << "??" << w.x << " " << w.y << " " << w.z << endl;
		
	w.x *= -1;
	w.y *= -1;
	w.z *= -1;
	e[++tot] = (Ins) { p, l, w };
}

void gx(int p, Point a, Point b, Point c) {
	if (cmp(a.z, b.z) == 1) swap(a, b);
	if (cmp(a.z, c.z) == 1) swap(a, c);
	if (cmp(b.z, c.z) == 1) swap(b, c);
	long double S = area(a, b, c);
//	assert(cmp(a.z, b.z) != 0 || cmp(b.z, c.z) != 0);
	if (cmp(a.z, b.z) == 0) {
		long double Zmax = c.z, Zmin = a.z;
		long double V = S / (Zmax - Zmin) / (Zmax - Zmin);
		Point W = (Point) { V, - 2 * Zmax * V, V * Zmax * Zmax };
		add(p, Zmin, Zmax, W);
	} else {
//		assert(cmp(b.z, c.z) == 0);
	//	puts("zhezhongnidongwodetongma\n");
		long double Zmax = c.z, Zmin = a.z;
		long double V = S / (Zmax - Zmin) / (Zmax - Zmin);
		Point W = (Point) { -V, 2 * Zmin * V, -V * Zmin * Zmin+S };
		add(p, Zmin, Zmax, W);
	}
}

Point inline calc(Point a, Point b, long double z) {
///	assert(cmp(a.z, z) != 0);
//	assert(cmp(b.z, z) != 0);
	
	Point A, B;
	A = a, B = b;
	
	b = b - a;
	long double nd = (z - a.z) / b.z;
	b.x *= nd, b.y *= nd, b.z *= nd;
	a = a + b;
//	assert(cmp(a.z, z) == 0);
	a.z = z;
	
	B = B - A;
	A = a - A;
	long double ma = A.x / B.x, mb = A.y / B.y, mc = A.z / B.z;
	assert(cmp(A.x * B.y, A.y * B.x) == 0);
	assert(cmp(A.x * B.z, A.z * B.x) == 0);
	
	return a;
}

void ins(int p, Point a, Point b, Point c) {
	if (cmp(a.z, b.z) == 1) swap(a, b);
	if (cmp(a.z, c.z) == 1) swap(a, c);
	if (cmp(b.z, c.z) == 1) swap(b, c);
	add(p, -1, a.z, (Point) { 0, 0, area(a, b, c) });
	if (cmp(a.z, b.z) == 0 && cmp(b.z, c.z) == 0) {
	//	add(p, 0, a.z, area(a, b, c));
	} else if (cmp(a.z, b.z) == 0) {
		gx(p, a, b, c);
	} else if (cmp(b.z, c.z) == 0) {
		gx(p, a, b, c);
	} else {
	//	puts("qiege");
		Point D = calc(a, c, b.z);
		gx(p, b, D, c);
	//	cout<<area(b, D, c)<<"shshishis" << a.z << " -----------hahahahha " << area(b, D, a) << " " << area(b, a, c) << endl;
		add(p, a.z, b.z, (Point) { 0, 0, area(b, D, c) });
		gx(p, b, D, a);
	}
}

long double inline Get(long double x, Point v) {
	return v.x * x * x + v.y * x + v.z;
}

int inline nb(int x, int y) {
	return A[x].z < A[y].z ? y : x;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(A[i].x), read(A[i].y), read(A[i].z), f[i] = i, sz[i] = 1;
	read(m);
	for (int i = 1; i <= m; i++) {
		int a, b, c; read(a), read(b), read(c);
		ins(nb(nb(a, b), c), A[a], A[b], A[c]);
		Add(a, b), Add(b, c);
		Add(a, c);
	//	cout << aaa << endl;
	}
	//cout << aaa << endl;
	read(q);
	for (int i = 1; i <= q; i++) {
		int h, p; read(h), read(p);
		if (cmp(A[p].z, h) <= 0) {
			ans[i] = -1;
			fk[i] = 1;
		} else {
			Q[++t] = (Qu) { h, p, i };
		}
	}
	sort(e + 1, e + 1 + tot);
	sort(h + 1, h + 1 + le);
	sort(Q + 1, Q + 1 + t);
	for (int i = t, j = le, k = tot; i; i--) {
		while (k && e[k].z > Q[i].h) {
			int u = find(e[k].x);
			g[u] = g[u] + e[k].w;
			k--; 
		}
		while (j && h[j].z > Q[i].h) {
			merge(h[j].x, h[j].y);
			j--;
		}
		//cout << sz[find(Q[i].p)] << " final " << k << " ???" << e[k].z << " dddhdhhd\n";
		ans[Q[i].id] = Get(Q[i].h, g[find(Q[i].p)]);
	}
	for (int i = 1; i <= q; i++) {
		if (fk[i]) {
			puts("-1");
			continue;
		}
		printf("%.14lf\n", (double)ans[i]);
	}
    return 0;
}
#include <bits/stdc++.h>

#define cd const long long &
int sgn (cd x) { return x < 0 ? -1 : x > 0; }
int cmp (cd x, cd y) { return sgn (x - y); }
long long sqr (cd x) { return x * x; }

#define cp const point &
struct point {
	long long x, y;
	explicit point (cd x = 0, cd y = 0) : x (x), y (y) {}
	int dim () const { return sgn (y) == 0 ? sgn (x) > 0 : sgn (y) > 0; }
	point rot90 () const { return point (-y, x); }
	point _rot90 () const { return point (y, -x); }
};
bool operator < (cp a, cp b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
point operator - (cp a) { return point (-a.x, -a.y); }
point operator + (cp a, cp b) { return point (a.x + b.x, a.y + b.y); }
point operator - (cp a, cp b) { return point (a.x - b.x, a.y - b.y); }
point operator * (cp a, cd b) { return point (a.x * b, a.y * b); }
point operator / (cp a, cd b) { return point (a.x / b, a.y / b); }
long long dot (cp a, cp b) { return a.x * b.x + a.y * b.y; }
long long det (cp a, cp b) { return a.x * b.y - a.y * b.x; }
long long dis2 (cp a, cp b = point ()) { return sqr (a.x - b.x) + sqr (a.y - b.y); }

bool turn_left (cp a, cp b, cp c) { return sgn (det (b - a, c - a)) >= 0; }
std::vector <point> convex_hull (std::vector <point> a) {
	int cnt = 0; std::sort (a.begin (), a.end ());
	static std::vector <point> ret; ret.resize (a.size () << 1);
	for (int i = 0; i < (int) a.size (); ++i) {
		while (cnt > 1 && turn_left (ret[cnt - 2], a[i], ret[cnt - 1])) --cnt; 
		ret[cnt++] = a[i]; }
	int fixed = cnt;
	for (int i = (int) a.size () - 1; i >= 0; --i) {
		while (cnt > fixed && turn_left (ret[cnt - 2], a[i], ret[cnt - 1])) --cnt;
		ret[cnt++] = a[i]; }
	return std::vector <point> (ret.begin (), ret.begin () + cnt - 1); }

struct node {
	long long a, b, c;
	node (cd a = 0, cd b = 0, cd c = 0) : a (a), b (b), c (c) {}
};

bool operator == (const node &a, const node &b) {
	return a.a == b.a && a.b == b.b && a.c == b.c;
}

bool operator < (const node &a, const node &b) {
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	return a.c < b.c;
}

bool operator > (const node &a, const node &b) {
	if (a.a != b.a) return a.a > b.a;
	if (a.b != b.b) return a.b > b.b;
	return a.c > b.c;
}

int min_rep (const std::vector <node> &str) {
	int n = str.size ();
    if (n <= 1) return 0;
    int p = 0, q = 1;
    while (p < n && q < n) {
        if (str[p] < str[q]) {
            q++;
        } else if (str[p] > str[q]) {
            p = q; q++;
        } else {
            int i, l = p, r = q;
            for (i = 0; i < n; i++) {
                int ll = l % n, rr = r % n;
                if (str[ll] < str[rr]) {
                    q = r; break;
                } else if (str[ll] > str[rr]) {
                    p = q; q = rr; break;
                }
                l++; r++;
            }
            if (i == n) break;
        }
    }
    return p;
}

int N, M;
std::vector <point> p, q;
std::vector <node> a, b;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M; p.resize (N); q.resize (M);
	for (int i = 0; i < N; ++i) std::cin >> p[i].x >> p[i].y;
	for (int i = 0; i < M; ++i) std::cin >> q[i].x >> q[i].y;
	std::vector <point> cvp = convex_hull (p), cvq = convex_hull (q);
	for (int i = 0; i < cvp.size (); ++i) {
		int j = (i + 1) % cvp.size (), k = (i - 1 + cvp.size ()) % cvp.size ();
		a.emplace_back (dis2 (cvp[i], cvp[j]), dot (cvp[k] - cvp[i], cvp[j] - cvp[i]), det (cvp[k] - cvp[i], cvp[j] - cvp[i]));
	}
	for (int i = 0; i < cvq.size (); ++i) {
		int j = (i + 1) % cvq.size (), k = (i - 1 + cvq.size ()) % cvq.size ();
		b.emplace_back (dis2 (cvq[i], cvq[j]), dot (cvq[k] - cvq[i], cvq[j] - cvq[i]), det (cvq[k] - cvq[i], cvq[j] - cvq[i]));
	}
	int n = min_rep (a), m = min_rep (b);
	if (a.size () != b.size ()) return std::cout << "NO\n", 0;
	for (int i = 0; i < a.size (); ++i) {
		if (!(a[(n + i) % a.size ()] == b[(m + i) % b.size ()])) return std::cout << "NO\n", 0;
	}
	std::cout << "YES\n";
}
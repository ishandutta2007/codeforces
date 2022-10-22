#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;
const int N = 1e5 + 5;
int n, m, c[N], ans[N];
typedef pair <int, int> pii; 
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
pii vec(int x, int y) {
	int d = gcd(abs(x), abs(y));
	return make_pair(x / d, y / d);
} vector <pii> poly[N], q[N];
map <pii, int> lst;
void add(int i, int v) { if(i) for(; i <= n; i += i & -i) c[i] += v; }
int qry(int i, int r = 0) { for(; i; i &= i - 1) r += c[i]; return r; }
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	int k, x0, y0, x1, y1, x2, y2;
	rep(i, 1, n) {
		scanf("%d%d%d", &k, &x0, &y0), x1 = x0, y1 = y0;
		while(--k) scanf("%d%d", &x2, &y2), poly[i].pb(vec(x2 - x1, y2 - y1)), x1 = x2, y1 = y2;
		poly[i].pb(vec(x0 - x1, y0 - y1));
	}
	cin >> m;
	rep(i, 1, m) scanf("%d%d", &x0, &y0), q[y0].pb(make_pair(x0, i));
	rep(r, 1, n) {
		for(pii v : poly[r]) add(r, 1), add(lst[v], -1), lst[v] = r;
		for(auto [l, id] : q[r]) ans[id] = qry(r) - qry(l - 1);
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0; 
}
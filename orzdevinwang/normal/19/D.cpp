#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size()) 
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7; 
const ll buf = 1e9 + 7;
int n, m, Px[N], Py[N];
struct node {
	int l, r, x, y, op, id;
} s[N], z[N];
map < ll, int > mp;
char ch[N];
ll P(int x, int y) { return x * buf + y; }
int mn[N << 2];
void add(int x, int l, int r, int w, int L, int R) {
	if(l <= L && R <= r) { mn[x] = w == -1 ? n + 1 : min(mn[x], w); return; }
	int mid = (L + R) >> 1; 
	if(l <= mid) { add(x << 1, l, r, w, L, mid); };
	if(r > mid) { add(x << 1 | 1, l, r, w, mid + 1, R); }; 
}
int qry(int x, int u, int L, int R) {
	if(L == R) { return mn[x]; }
	int mid = (L + R) >> 1;
	if(u <= mid) { return min(mn[x], qry(x << 1, u, L, mid)); }
	else { return min(mn[x], qry(x << 1 | 1, u, mid + 1, R)); }
}
void cdq(int l, int r) {
	if(l == r) { return; }
	int mid = (l + r) >> 1;
	cdq(l, mid), cdq(mid + 1, r);
	int p1 = l, p2 = mid + 1, p = l;
	while(p1 <= mid || p2 <= r) {
		if(p1 <= mid && (p2 > r || s[p1].y >= s[p2].y)) {
			if(s[p1].op == 1) add(1, s[p1].l, s[p1].r, s[p1].id, 1, n);
			z[p] = s[p1], p++, p1++;
		}
		else {
			if(s[p2].op == 2) s[p2].id = min(s[p2].id, qry(1, s[p2].l, 1, n));
			z[p] = s[p2], p++, p2++;
		}
	} 
	L(i, l, mid) if(s[i].op == 1) add(1, s[i].l, s[i].r, -1, 1, n);
	L(i, l, p - 1) s[i] = z[i];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n << 2) mn[i] = n + 1;
	L(i, 1, n) {
		int x, y;
		cin >> (ch + 1) >> x >> y;
		if(ch[1] == 'a') { ++m, s[m].x = x, s[m].y = y, s[m].l = i, s[m].r = n, s[m].op = 1, mp[P(x, y)] = m, s[m].id = n + 1; }
		if(ch[1] == 'r') { s[mp[P(x, y)]].r = i, mp[P(x, y)] = 0; }
		if(ch[1] == 'f') { ++m, s[m].x = x + 1, s[m].y = y + 1, s[m].l = i, s[m].r = i, s[m].op = 2, s[m].id = n + 1; }
	}
	sort(s + 1, s + m + 1, [&] (node a, node b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	});
	L(i, 1, m) if(s[i].op == 1) s[i].id = i, Px[i] = s[i].x, Py[i] = s[i].y;
	sort(s + 1, s + m + 1, [&] (node a, node b) {
		return a.x == b.x ? (a.y == b.y ? a.op < b.op : a.y > b.y) : a.x > b.x;
	});
	cdq(1, m);
	sort(s + 1, s + m + 1, [&] (node a, node b) {
		return a.l < b.l;
	});
	L(i, 1, m) { if(s[i].op == 2) {
		if(s[i].id == n + 1) { cout << "-1\n"; }
		else { cout << Px[s[i].id] << " " << Py[s[i].id] << "\n"; }
	} }
	return 0;
}
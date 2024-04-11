#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n, sz[N];
struct node {
	int x, a, b, dp;
} s[N];
void add (int x, int w) {
	for (; x <= N - 1; x += x & -x) 
		sz[x] = max(sz[x], w);
}
void cle (int x) {
	for (; x <= N - 1; x += x & -x) 
		sz[x] = 0;
}
int query (int x) {
	int ret = 0;
	for (; x; x -= x & -x) 
		ret = max(ret, sz[x]);
	return ret;
}
void divide (int l, int r) {
	if(l == r) return ;
	int mid = (l + r) >> 1;
	divide (l, mid);
	sort(s + l, s + mid + 1, [&] (node x, node y) {
		return x.a < y.a;
	});
	sort(s + mid + 1, s + r + 1, [&] (node x, node y) {
		return x.a < y.a;
	});
	
	int p1 = l, p2 = mid + 1;
	while (p1 <= mid && p2 <= r) {
		if(s[p1].a <= s[p2].a) add (s[p1].b + 1, s[p1].dp + 1), ++p1;
		else s[p2].dp = max(s[p2].dp, query (s[p2].b)), ++p2;
	}
	while (p2 <= r) s[p2].dp = max(s[p2].dp, query (s[p2].b)), ++p2;
	L(i, l, p1 - 1) cle(s[i].b + 1);
	
	sort(s + l, s + r + 1, [&] (node x, node y) {
		return x.x < y.x;
	});
	
	divide (mid + 1, r);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) s[i].x = i, cin >> s[i].a, s[i].a = i - s[i].a, s[i].b = i - s[i].a;
	int pn = 0;
	L(i, 1, n) if(0 <= s[i].a && s[i].a < i) ++pn, swap(s[pn], s[i]);
	n = pn;
	if(pn == 0) return cout << 0 << '\n', 0;
	L(i, 1, pn) s[i].dp = 1;
	divide (1, n);
	int mx = 0;
	L(i, 1, n) mx = max(mx, s[i].dp);
	cout << mx << '\n';
	return 0;
}
/*
6
8 8 2 8 6 4 

*/
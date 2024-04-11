#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define x first
#define y second

using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n; pair <ll, ll> a[N];
struct node {
	ll mi, ma;
	node(ll mi = 2e9, ll ma = -2e9) :mi(mi), ma(ma) {}
	node operator +(const node& b) { return node(min(mi, b.mi), max(ma, b.ma)); }
	int chk(ll mid) { return ma - mi <= mid; }
} pre[N], suf[N];
int chk(ll mid) {
	rep(i, 1, n) pre[i] = pre[i-1] + node(a[i].y, a[i].y);
	per(i, n, 1) suf[i] = suf[i+1] + node(a[i].y, a[i].y);
	int r = 1; rep(l, 1, n) {
		while(r < n && a[r+1].x <= a[l].x + mid) r++;
		if((pre[l-1] + suf[r+1]).chk(mid)) return 1;
	} return 0;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n; int x, y;
	rep(i, 1, n) {
		scanf("%d%d", &x, &y);
		a[i].x = x - y, a[i].y = x + y;
	}
	sort(a + 1, a + n + 1);
	ll l = 0, r = 2e9, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		if(chk(mid)) r = mid - 1; else l = mid + 1;
	} printf("%.16lf", l / 2.0);
	return 0;
}
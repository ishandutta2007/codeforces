#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e5 + 9;
const char prt[2][3] = { "LU", "DR" };
typedef long long ll;
typedef double ld;
int n, l;
struct con {
	ll x, y, k, w;
	int read() {
		ll t, a, b; scanf("%lld%lld%lld", &t, &a, &b);
		x = a - b + t, y = a + b + t, k = t / l, w = t % l;
		if(x % 2 || y % 2) return 0;
		x /= 2, y /= 2; return 1;
	}
	bool operator <(const con& b)const { return w < b.w; }
} a[N];
void updL(ll& l, ll a, ll b) { if(b < 0) a = -a, b = -b; if(a >= 0) l = max(l, (a + b - 1) / b); }
void updR(ll& r, ll a, ll b) { r = min(r, a / b); }
int main() {
	cin >> n >> l;
	rep(i, 1, n) if(!a[i].read()) puts("NO"), exit(0);
	a[++n] = { 0, 0, 0, 0 }, a[++n] = { 0, 0, -1, l };
	sort(a + 1, a + n + 1);
	ll lx = -8e18, rx = 8e18, ly = -8e18, ry = 8e18;
	rep(i, 2, n) {
		ll k = a[i].k - a[i-1].k, w = a[i].w - a[i-1].w, x = a[i].x - a[i-1].x, y = a[i].y - a[i-1].y;
		if(!k && (x > w || y > w)) puts("NO"), exit(0);
		if(k > 0) updL(lx, x - w, k), updR(rx, x, k), updL(ly, y - w, k), updR(ry, y, k);
		if(k < 0) updL(lx, x, k), updR(rx, x - w, k), updL(ly, y, k), updR(ry, y - w, k);
	}
	if(lx > rx || ly > ry) puts("NO"), exit(0);
	ll p = 0, x = 0, y = 0;
	rep(i, 1, n) {
		ll X = a[i].x - a[i].k * lx, Y = a[i].y - a[i].k * ly;
		for(int fx, fy; p < a[i].w; fx = x < X, fy = y < Y, putchar(prt[fx][fy]), x += fx, y += fy, p++);
	}
	return 0;
}
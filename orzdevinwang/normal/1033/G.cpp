#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define i128 __int128
using namespace std;
const int N = 1e6 + 7;
int n, m, r[N], mn1, mn2;
ll a[N];
ll ns1, ns2;
int main () {
//	return system("fc review.out ex_review3.out"), 0;
//	freopen("review.in", "r", stdin);
//	freopen("review.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i];
	L(v, 2, m * 2) {
		int tl = max(v - m, 1), tr = min(v - 1, m); 
		L(i, 1, n) r[i] = a[i] % v;
		mn1 = 0, mn2 = 0;
		L(i, 1, n) 
			if(r[i] > mn1) mn2 = mn1, mn1 = r[i];
			else if(r[i] > mn2) mn2 = r[i];
		mn1 = mn1 / 2 + 1, mn2 = mn2 / 2 + 1;
		r[n + 1] = v - 1;
		int mid = v >> 1, vl = 0, vr = v - 1, cnt = 0;
		L(i, 1, n) {
//			Last r[i - 1] + 1 <= v / 2 
			if(r[i] + 1 <= mid) vl = max(vl, r[i]);
			else vr = min(vr, r[i]), cnt += 1;
		}
		vl += 1;
		if(vl * 2 <= v && v <= vr * 2) {
			if(cnt & 1) {
				int xl = max(max(vl, mn2), tl), xr = min(tr, vr);
				int zl = max(xl, v - xr), zr = min(xr, v - xl);
				if(zl <= zr) ns1 += zr - zl + 1;
			} else {
				int xl = max(max(vl, mn1), tl), xr = min(tr, vr);
				int zl = max(xl, v - xr), zr = min(xr, v - xl);
				if(zl <= zr) ns2 += zr - zl + 1;
			}
		}
	}
	ll zs = (ll) m * m - ns1 - ns2;
	cout << zs / 2 << ' ' << zs / 2 << ' ' << ns1 << ' ' << ns2 << '\n';
	return 0;
}
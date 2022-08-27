#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1 << 19;
namespace rpoly {
	const double pi = acos (-1);
	struct cp {
		double x, y;
		cp (double X = 0, double Y = 0) {
			x = X;
			y = Y;
		}
	};
	cp operator + (cp a, cp b) {
		return cp (a.x + b.x, a.y + b.y);
	}
	cp operator - (cp a, cp b) {
		return cp (a.x - b.x, a.y - b.y);
	}
	cp operator * (cp a, cp b) {
		return cp (a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
	}
	int Lim;
	cp pw[N + 1];
	void pinit (int x) {
		for (Lim = 1; Lim <= x; Lim <<= 1);
		L(i, 0, Lim) pw[i] = cp (cos (pi * 2 / Lim * i), sin (pi * 2 / Lim * i));
	}
	int rev[N];
	void itrev (int n) {
		L(i, 0, n - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
	}
	void dft (cp *a, int op, int n) {
		L(i, 0, n - 1) 
			if(i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 2; i <= n; i <<= 1) 
			for (int j = 0, l = i >> 1; j < n; j += i) 
				for (int k = j, ch = 0; k < j + l; ++k) {
					cp u = a[k], v = a[k + l] * pw[op == 1 ? ch : Lim - ch];
					a[k] = u + v;
					a[k + l] = u - v;
					ch += Lim / i;
				}
		if(op != 1) 
			L(i, 0, n - 1) 
				a[i].x /= n, a[i].y /= n;
	} 
	cp sa[N], sb[N];
	void mul (int *a, int *b, ll *ns, int n, int m) {
		int pn = n + m, lm = 1;
		for (; lm <= pn; lm <<= 1) ;
		itrev (lm);
		L(i, 0, lm - 1) sa[i] = sb[i] = cp ();
		L(i, 0, n) sa[i] = cp (a[i], 0);
		L(i, 0, m) sb[i] = cp (b[i], 0);
		dft (sa, true, lm);
		dft (sb, true, lm);
		L(i, 0, lm - 1) sa[i] = sa[i] * sb[i];
		dft (sa, false, lm);
		L(i, 0, pn) ns[i] = floor ( sa[i].x + 0.49 );
	}
}
int n, m, q, V, a[N], b[N], ns;
int xa[N], xb[N];
ll xc[N];
int ya[N], yb[N];
ll yc[N];
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m >> q;
	L(i, 1, n) cin >> a[i], V = max(V, a[i]);
	L(i, 1, m) cin >> b[i], V = max(V, b[i]);
	rpoly :: pinit(V * 2 + 1);
	L(i, 1, n) xa[a[i]] += 1, ya[a[i]] += 1;
	L(i, 1, n - 1) xa[min(a[i], a[i + 1])] -= 1, ya[max(a[i], a[i + 1])] -= 1;
	L(i, 1, m) xb[b[i]] += 1, yb[b[i]] += 1;
	L(i, 1, m - 1) xb[min(b[i], b[i + 1])] -= 1, yb[max(b[i], b[i + 1])] -= 1;
	rpoly :: mul (xa, xb, xc, V, V);
	rpoly :: mul (ya, yb, yc, V, V);
	R(i, N - 2, 0) xc[i] += xc[i + 1]; 
	L(i, 1, N - 1) yc[i] += yc[i - 1];
	while (q--) {
		int x;
		cin >> x;
		cout << xc[x] - yc[x - 1] << '\n';	
	}
	return 0;
}
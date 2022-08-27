#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7, S = sqrt(N);
int mx = 0, Bs, B;
struct BLOCK {
	ll sum[N], val[N]; 
	inline void add(int x, int y) {
		int sy = (x + B - 1) / B;
		L(i, sy, Bs) sum[i] += y;
		L(i, x, min(sy * B, mx)) val[i] += y;
	}
	inline ll qzh (int x) {
		return x ? sum[(x - 1) / B] + val[x] : 0;
	}
	inline ll query (int l, int r) {
		return qzh(r) - qzh(l - 1);
	}
} bl1, bl2;

int n, a[N], p;
ll f[N];
inline ll calc1 (int k) {
	ll res = 0;
	for(int l = 1, r; l <= k; l = r + 1) 
		r = k / (k / l), res += (k / l) * bl2.query(l, r);
//	L(i, 1, p - 1) res += a[p] / a[i] * a[i];
	return res;
}


inline ll calc2 (int k) {
	ll res = 0;
	if(k <= B) return f[k];
	L(i, 1, mx / k) res += i * bl1.query(i * k, min((i + 1) * k - 1, mx));
//	L(i, 1, p - 1) res += a[i] / a[p];
	return res;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll ns = 0, sum = 0; 
	cin >> n;
	L(i, 1, n) cin >> a[i], mx = max(mx, a[i]);
	B = sqrt(mx), Bs = (mx + B - 1) / B;
	L(i, 1, n) {
		p = i, ns += (ll) a[i] * (i - 1) + sum; 
		ns -= calc1 (a[i]);
		ns -= calc2 (a[i]) * a[i];
		cout << ns << " ";
		sum += a[i]; 
		bl1.add(a[i], 1), bl2.add(a[i], a[i]); 
		L(j, 1, B) f[j] += a[i] / j;
	}
	return 0;
}
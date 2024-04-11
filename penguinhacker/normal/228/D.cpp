#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, q, a[mxN];
struct ft {
	ll a[mxN+1];
	void upd(int i, ll val) {for (++i; i<=n; i+=i&-i) a[i]+=val;}
	ll sum(int i) {ll res=0; for (++i; i>0; i-=i&-i) res+=a[i]; return res;}
	ll sum(int l, int r) {return sum(r)-sum(l-1);}
} f[5][10];

inline ll get(int i, int j, int ind) {int res=(ind-j+2*(i-1))%(2*(i-1)); if (res>=i) res=2*(i-1)-res; return res+1;}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=2; i<=6; ++i) for (int j=0; j<2*(i-1); ++j) for (int k=0; k<n; ++k) f[i-2][j].upd(k, get(i, j, k)*a[k]);
	cin >> q;
	while(q--) {
		int t; cin >> t;
		if (t==1) {
			int ind, val; cin >> ind >> val, --ind;
			int inc=val-a[ind]; a[ind]=val;
			for (int i=2; i<=6; ++i) for (int j=0; j<2*(i-1); ++j) f[i-2][j].upd(ind, get(i, j, ind)*inc);
		}
		else {
			int l, r, z; cin >> l >> r >> z, --l, --r;
			cout << f[z-2][l%(2*(z-1))].sum(l, r) << '\n';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
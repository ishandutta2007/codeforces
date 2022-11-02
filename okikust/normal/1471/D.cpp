#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;


int main() {
	int t, n, k, m;
	int x, y, z;
	ll w;
	int mx, s0;
	int s, ans;
	vector<int>p;
	bool prim[1010];
	vector<int>a;
	int sz;
	rep(i, 1010)prim[i] = true;
	prim[0] = false;
	prim[1] = false;
	rep2(i, 2, 1000) {
		if (prim[i]) {
			p.pb((i*i));
			x = 2 * i;
			while (x <= 1000) {
				prim[x] = false;
				x += i;
			}
		}
	}
	sz = p.size();
	cin >> t;
	rep(tt, t) {
		a.clear();
		cin >> n;
		rep(i, n) {
			cin >> x;
			rep(j, sz) {
				if (p[j] > x)break;
				while (x % p[j] == 0) {
					x /= p[j];
				}
			}
			a.pb(x);
		}
		sort(all(a));
		mx = 1;
		s0 = 0;
		k = 1;
		rep(i, n - 1) {
			if (a[i] == a[i + 1])k++;
			else {
				mx = max(mx, k);
				if (a[i] == 1) {
					s0 += k;
				}
				else if (!(k & 1))s0 += k;
				k = 1;
			}
		}
		mx = max(mx, k);
		if (a[n - 1] == 1) {
			s0 += k;
		}
		else if (!(k & 1))s0 += k;
		s0 = max(s0, mx);
		cin >> m;
		rep(i, m) {
			cin >> w;
			if (w == 0)cout << mx << "\n";
			else cout << s0 << "\n";
		}
	}
	return 0;
}
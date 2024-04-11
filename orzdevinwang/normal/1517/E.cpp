#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n, m;
ll a[N], pre[N], pz[N];
int calc(int u, int r, ll p) {
	int l = 1, ns = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pz[u + 2 * mid] <= p) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ns + 1;
}
void rmain() {
	ll ans = 0;
	cin >> n;
	L(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i], pz[i] = a[i];
	if(n == 1) return cout << "1\n", void();
	L(i, 2, n) pz[i] += pz[i - 2];
	ll upt = (pre[n] - 1) / 2;


	// P...C : P CCCCC PCPC PPPPPPP C
	L(i, 2, n - 2) {
		ll p = upt - pre[i] + a[1] - a[n];
		if(p >= 0) ans += calc(i, (n - 2 - i) / 2, p + pz[i]);
	}
	L(i, 1, n - 1) if(pre[n] - pre[i] <= upt) ans ++;
//	cout << ans << "\n";


	// C...C : CCCCC PCPC PPPPPPP C
	L(i, 1, n - 2) {
		ll p = upt - pre[i] - a[n];
		if(p >= 0) ans += calc(i, (n - 2 - i) / 2, p + pz[i]);
	}
//	cout << ans << "\n";


	// P...P : P CCCCC PCPC PPPPPPP
	L(i, 2, n - 1) {
		ll p = upt - pre[i] + a[1];
		if(p >= 0) ans += calc(i, (n - 1 - i) / 2, p + pz[i]);
	}
	++ ans;
//	cout << ans << "\n";


	// C...P : CCCCC PCPC PPPPPPP
	L(i, 1, n - 1) {
		ll p = upt - pre[i];
		if(p >= 0) ans += calc(i, (n - 1 - i) / 2, p + pz[i]);
	}
	cout << ans % 998244353 << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}
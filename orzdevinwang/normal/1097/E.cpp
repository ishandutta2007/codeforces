#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e5 + 7;
int n, B, a[N], vis[N], f[N], dp[N], c[N];
void add (int x, int w) {
	for (; x <= n; x += x & -x) f[x] = max(f[x], w);
}
int query (int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret = max(ret, f[x]);
	return ret;
}
int stk[N], tp;
vi mk[N];
vector < vi > rm;
void Main () {
	rm.clear ();
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) vis[i] = false, mk[i].clear ();
	int pn = n;
	while (pn > 0) {
		L(i, 1, n) f[i] = 0;
		int mx = 0, now = n + 1;
		L(i, 1, n) if(!vis[a[i]]) dp[i] = query (a[i]) + 1, add (a[i], dp[i]), mx = max(mx, dp[i]);	
		if(mx <= c[pn]) {
			tp = 0;
			L(i, 1, n) if(!vis[a[i]]) {
				int p = lower_bound(stk + 1, stk + tp + 1, a[i]) - stk;
				if(p > tp) stk[++tp] = a[i], mk[tp].push_back(a[i]);
				else stk[p] = a[i], mk[p].push_back(a[i]);
			}
			L(i, 1, tp) rm.push_back(mk[i]);
			break ;
		}
		vi vc;
		R(i, n, 1) if(!vis[a[i]] && dp[i] == mx && now >= a[i]) vc.push_back(a[i]), mx -= 1, now = a[i];
		reverse(vc.begin(), vc.end());
		pn -= sz(vc);
		for (const int &x : vc) vis[x] = true;
		rm.push_back(vc);
	}
	cout << sz(rm) << '\n';
	for (const vi &u : rm) {
		cout << sz(u) << ' ';
		L(i, 0, sz(u) - 1) cout << u[i] << ' ';
		cout << '\n';
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int cur = 0, pwp = 0;
	while (cur < N) {
		pwp += 1;
		L(j, cur, min(cur + pwp - 1, N - 1)) c[j] = pwp - 1;
		cur += pwp;
	}
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}
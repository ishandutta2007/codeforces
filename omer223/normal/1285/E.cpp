#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pii> dat;

void solve() {
	int n;
	cin >> n;
	vector<pii> segs(n);
	vector<pair<int, pii>> par1;
	vector<int> par;
	foru(i, 0, n) {
		cin >> segs[i].ff >> segs[i].ss; segs[i].ss++;
		par1.pb({ segs[i].ff,{1,i} });
		par1.pb({ segs[i].ss,{0,i} });
	}
	sort(par1.begin(), par1.end());
	vector<pii> toind(n);
	int prv = -1e9 - 5, cnt = 0, prvsgn = -1;
	for (auto ii : par1) {
		if (ii.ff != prv || ii.ss.ff != prvsgn) {
			if (prv != -1e9 - 5)
				par.pb(prvsgn == 1 ? cnt : -cnt);
			cnt = 0;
		}
		cnt++;
		prv = ii.ff;
		prvsgn = ii.ss.ff;
		if (ii.ss.ff)toind[ii.ss.ss].ff = par.size();
		else toind[ii.ss.ss].ss = par.size();
	}
	if (prv != -1e9-5)
		par.pb(prvsgn == 1 ? cnt : -cnt);
	vector<int> pre(2 * n, 0), pre1(2 * n, 0);
	cnt = 0;
	int m = par.size();
	foru(i, 0, m)
		pre[i] = (i ? pre[i - 1] : 0) + par[i], cnt += (pre[i] == 0);
	foru(i, 0, m)
		pre1[i] = (i ? pre1[i - 1] : 0) + (pre[i] == 1 ? 1 : 0);
	int bst = 0;
	foru(i, 0, n) {
		int l = toind[i].ff+1, r = toind[i].ss-1;
		if (l > r)bst = max(bst, cnt - 1);
		int tot = (pre1[r] - (l ? pre1[l - 1] : 0)) - (pre[r + 1] == 0 && par[r+1]==-1);
		bst = max(bst, tot + cnt);
	}
	cout << bst << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

ll MOD = 1000000007LL;

pll comb(pll a, pll b) {
	if(a.f < b.f) return a;
	if(b.f < a.f) return b;
	return mp(a.f, (a.s+b.s)%MOD);
}

pll seg[200005*8];
void ins(int i, int l, int r, int vi, pll v) {
	seg[i] = comb(seg[i], v);
	if(l != r-1) {
		int m = (l+r)/2;
		if(vi < m) ins(2*i+1, l, m, vi, v);
		else ins(2*i+2, m, r, vi, v);
	}
}
pll get(int i, int l, int r, int ql, int qr) {
	if(ql < l) ql = l;
	if(qr > r) qr = r;
	if(ql >= r || qr <= l) return mp(0,0);
	if(ql == l && qr == r) return seg[i];
	int m = (l+r)/2;
	return comb(get(2*i+1, l, m, ql, qr), get(2*i+2, m, r, ql, qr));
}
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	F0R(i, 200005*8) seg[i] = mp(0,0);
	map<int,int> xm;
	map<int,int> rev;
	set<int> s;
	vector<pii> v; F0R(i, n) {
		int a, b; cin >> a >> b;
		v.pb(mp(a,b));
		s.insert(a); s.insert(b);
	}
	int cnt = 1;
	for(auto x : s) rev[xm[x] = cnt++] = x;
	sort(v.begin(),v.end());
	int lim = 0;
	ins(0, 0, cnt, 0, mp(0, 1));
	for(auto x : v) {
		lim = max(lim, x.s);
		auto a = get(0, 0, cnt, 0, xm[x.s]+1);
		ins(0, 0, cnt, xm[x.f], mp(-x.f+x.s+a.f, a.s));
	}
	ll ans = 0;
	int best = 1000000000;
	F0R(i, cnt) {
		if(rev[i] <= lim) continue;
		auto x = get(0, 0, cnt, i, i+1);
		if(x.f+rev[i] > best) continue;
		if(x.f+rev[i] == best) ans = (ans + x.s) % MOD;
		else {
			best = x.f+rev[i];
			ans = x.s;
		}
	}
	cout << ans << endl;
///
	return 0;
}
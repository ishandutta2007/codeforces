#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl p;
	if (n % 2) {
		for (ll i = 1; i <= n; i += 2) p.pb(i);
		for (ll i = n-2; i >= 1; i -= 2) p.pb(i);
		p.pb(n);
		for (ll i = 2; i <= n-1; i += 2) p.pb(i);
		for (ll i = n-1; i >= 2; i -= 2) p.pb(i);
	} else {
		for (ll i = 1; i <= n-1; i += 2) p.pb(i);
		for (ll i = n-1; i >= 1; i -= 2) p.pb(i);
		p.pb(n);
		for (ll i = 2; i <= n; i += 2) p.pb(i);
		for (ll i = n-2; i >= 2; i -= 2) p.pb(i);
	}
	FOR(i,0,2*n) cout << p[i] << " \n"[i+1==2*n];
/*	vl d(n);
	vb mark(n);
	FOR(i,0,2*n) {
		if (!mark[p[i]-1]) d[p[i]-1] -= i, mark[p[i]-1] = true;
		else d[p[i]-1] += i;
	}
	ll cur = 0;
	FOR(i,1,n+1) cur += (n-i)*abs(abs(d[i-1]) + i - n);
	cout << cur << endl;
	if (cur == 0) {
		FOR(i,0,2*n) cout << p[i] << " \n"[i+1==2*n];
	}
*/
/*
	FOR(i,0,n) p[2*i] = p[2*i+1] = i;
	sort(all(p));
	do {
		vl d(n);
		vb mark(n);
		FOR(i,0,2*n) {
			if (!mark[p[i]]) d[p[i]] -= i, mark[p[i]] = true;
			else d[p[i]] += i;
		}
		ll cur = 0;
		FOR(i,1,n+1) cur += (n-i)*abs(abs(d[i-1]) + i - n);
		if (cur == 0) {
			FOR(i,0,2*n) cout << p[i]+1 << " \n"[i+1==2*n];
		
		}
	
	} while (next_permutation(all(p)));
*/
}
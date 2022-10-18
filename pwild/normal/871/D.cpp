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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

ll solve_slow(ll n) {
	vvl dist(n,vl(n,oo));
	FOR(i,0,n) FOR(j,0,n) if (__gcd(i+1,j+1) > 1) dist[i][j] = 1;
	FOR(i,0,n) dist[i][i] = 0;

	FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	
	ll res = 0;
	FOR(i,0,n) FOR(j,i+1,n) if (dist[i][j] < oo) res += dist[i][j];
	return res;

}

ll triangle(ll n) { return n*(n-1)/2; }

ll solve(ll n) {
	vl pf(n+1), mu(n+1), phi(n+1), cnt(n+1), sum(n+2);
	iota(all(pf),0);
	FOR(i,2,n+1) if (pf[i] == i) {
		for (ll j = i*i; j <= n; j += i) pf[j] = min(pf[j],i);
	}
	
	ll cnt1 = 0, cnt2 = 0, cnt3 = 0, m = 0;

	mu[1] = phi[1] = 1;
	FOR(i,2,n+1) {
		ll j = i/pf[i];
		if (pf[i] == pf[j]) {
			mu[i] = 0, phi[i] = pf[i]*phi[j];
		} else {
			mu[i] = -mu[j], phi[i] = (pf[i]-1)*phi[j];
		}
		if (pf[i] == i && i > n/2) continue;
		m++;
		cnt[pf[i]]++;
		cnt1 += i-1-phi[i];
	}

	FORD(i,0,n+1) sum[i] = cnt[i]+sum[i+1];
	
	FOR(i,2,n+1) cnt3 += cnt[i] * sum[max(i,n/i)+1];

	cnt2 = triangle(m) - cnt1 - cnt3;

	return 1*cnt1 + 2*cnt2 + 3*cnt3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//FOR(n,1,100) assert(solve(n) == solve_slow(n));
	
	ll n; cin >> n;
	cout << solve(n) << endl;

}
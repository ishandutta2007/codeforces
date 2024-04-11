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
	vector<double> p(n);
	FOR(i,0,n) cin >> p[i], p[i] /= 100;
	
	const ll N = 300000;
	vector<double> pr(N+1);
	
	vector<double> q(n);
	FOR(i,0,n) q[i] = 1-p[i];
	pr[n] = 1;
	FOR(i,0,n) pr[n] *= p[i];

	priority_queue<pair<double,ll>> pq;
	FOR(i,0,n) pq.push({(1-q[i]*(1-p[i]))/(1-q[i]),i});
	FOR(k,n+1,N+1) {
		double fac; ll i;
		tie(fac,i) = pq.top();
		pq.pop();
		pr[k] = fac*pr[k-1];
		q[i] *= 1-p[i];
		pq.push({(1-q[i]*(1-p[i]))/(1-q[i]),i});
	}
	double res = N*pr[N];
	FOR(k,0,N) res -= pr[k];
	cout << fixed << setprecision(12) << res << endl;
}
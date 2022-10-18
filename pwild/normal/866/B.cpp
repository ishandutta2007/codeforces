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

struct person {
	ll a, b, s;
	bool operator<(const person &p) const { return a-b > p.a-p.b; }
};

ll intersect(ll a, ll b, ll c, ll d) {
	return max(0LL,min(b,d)-max(c,a));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, S; cin >> n >> S;
	
	ll total = 0, positive = 0;
	vector<person> p(n);
	FOR(i,0,n) {
		ll s, a, b; cin >> s >> a >> b;
		p[i] = {a,b,s};
		total += s;
		if (a > b) positive += s;
	}
	sort(all(p));
	
	ll m = (total+S-1)/S, kk = positive/S;
	ll res = 0;
	FOR(dk,-1,2) {
		ll k = kk+dk;
		if (k < 0 || k > m) continue;
		ll cur = 0;
		
		if (k == 0) {
			FOR(i,0,n) cur += p[i].s*p[i].b;
		} else if (k == m) {
			FOR(i,0,n) cur += p[i].s*p[i].a;
		} else {
			ll slack = m*S - total;
			ll remA = k*S-slack, remB = (m-k)*S-slack;
			assert(remA >= 0 && remB >= 0);
			assert(remA <= total && remB <= total);
			ll sum = 0;
			FOR(i,0,n) {
				ll from = sum, to = sum + p[i].s;
				cur += intersect(from,to,0,remA) * p[i].a;
				cur += intersect(from,to,remA,remA+slack) * max(p[i].a,p[i].b);
				cur += intersect(from,to,remA+slack,total) * p[i].b;
				sum = to;
			}
		}
		res = max(res,cur);
	}
	cout << res << endl;
}
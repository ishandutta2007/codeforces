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

struct point {
	array<ll,3> x;
	ll i;
	bool operator<(point p) { return x < p.x; }
};

vector<point> a;

void match(ll i, ll j) {
	cout << a[i].i << " " << a[j].i << endl;
}

ll solve(ll i, ll j, ll d) {
	if (i == j) return -1;
	if (i+1 == j) return i;
	assert(d < 3);
	
	ll todo = -1;
	while (i < j) {
		ll k = i;
		while (k < j && a[k].x[d] == a[i].x[d]) k++;
		
		ll cur = solve(i,k,d+1);
		i = k;

		if (cur == -1) continue;
		
		if (todo != -1) {
			match(todo,cur);
			todo = -1;
		} else {
			todo = cur;
		}
	}
	return todo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	a.resize(n);
	FOR(i,0,n) {
		FOR(j,0,3) cin >> a[i].x[j];
		a[i].i = i+1;
	}
	sort(all(a));
	
	solve(0,n,0);
}
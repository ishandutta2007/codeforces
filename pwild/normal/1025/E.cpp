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

pll to(pll p, ll dir) {
	if (dir == 0) return {p.xx+1,p.yy};
	if (dir == 1) return {p.xx-1,p.yy};
	if (dir == 2) return {p.xx,p.yy+1};
	if (dir == 3) return {p.xx,p.yy-1};
	return {-1,-1};
}

ll n, m;


vvl to_diag(vvl a) {
	vvl res;
	
	auto add_move = [&](ll i1, ll j1, ll i2, ll j2) {
		res.pb({i1,j1,i2,j2});
		swap(a[i1][j1],a[i2][j2]);
	};

	ll J = 0;
	FOR(i,0,n) {
		vector<pll> todo;
		FOR(j,0,n) if (a[i][j] >= 0) todo.eb(j,J++);
		
		for (pll p: todo) if (p.xx > p.yy) FORD(j,p.yy,p.xx) add_move(i,j+1,i,j);
		reverse(all(todo));
		for (pll p: todo) if (p.xx < p.yy) FOR(j,p.xx,p.yy)  add_move(i,j,i,j+1);
	}
	
	FOR(j,0,m) {
		FOR(i1,0,n) if (a[i1][j] >= 0) {
			ll i2 = a[i1][j];
			if (i1 > i2) FORD(i,i2,i1) add_move(i+1,j,i,j);
			if (i1 < i2) FOR(i,i1,i2)  add_move(i,j,i+1,j);
			break;
		}
	}
	
	FOR(i,0,m) {
		FOR(j1,0,n) if (a[i][j1] >= 0) {
			ll j2 = a[i][j1];
			if (j1 > j2) FORD(j,j2,j1) add_move(i,j+1,i,j);
			if (j1 < j2) FOR(j,j1,j2)  add_move(i,j,i,j+1);
			break;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	vvl a(n,vl(n,-1)), b(n,vl(n,-1));

	FOR(k,0,m) {
		ll i, j; cin >> i >> j;
		i--, j--;
		a[i][j] = k;
	}
	FOR(k,0,m) {
		ll i, j; cin >> i >> j;
		i--, j--;
		b[i][j] = k;
	}
	
	auto resa = to_diag(a), resb = to_diag(b);
	reverse(all(resb));
	for (vl &v: resb) swap(v[0],v[2]), swap(v[1],v[3]);

	cout << sz(resa)+sz(resb) << endl;
	for (vl v: resa) FOR(k,0,4) cout << v[k]+1 << " \n"[k==3];
	for (vl v: resb) FOR(k,0,4) cout << v[k]+1 << " \n"[k==3];
}
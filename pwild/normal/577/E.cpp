#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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
#define xx 
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

struct point {
	ll x, y, i;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<point> p(n);
	FOR(i,0,n) cin >> p[i].x >> p[i].y, p[i].i = i+1;
	
	

	sort(all(p),[&](const point &a, const point &b) {
		if (a.x/1000 == b.x/1000) {
			if ((a.x/1000) % 2) return a.y < b.y; else return a.y > b.y;
		}
		return a.x < b.x;
	});
	
	FOR(i,0,n-1) cout << p[i].i << " ";
	cout << p[n-1].i << endl;

}
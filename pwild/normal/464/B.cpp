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

struct vec {
	union {
		ll a[3];
		struct { ll x, y, z; };
	};
	vec(ll i = 0, ll j = 0, ll k = 0) : a{i,j,k} {}
	ll &operator[](size_t i) { return a[i]; }
	const ll &operator[](size_t i) const { return a[i]; }
	vec operator+(const vec &v) const { return vec(x+v.x,y+v.y,z+v.z); }
	vec operator-(const vec &v) const { return vec(x-v.x,y-v.y,z-v.z); }
	ll operator%(const vec &v) const { return x*v.x + y*v.y + z*v.z; }
	vec operator*(const vec &v) const { return vec(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x); }
	bool operator==(const vec &v) const { return x == v.x && y == v.y && z == v.z; }
	bool operator!=(const vec &v) const { return !(*this == v); }
};

ll len2(vec v) { return v % v; }
ll d2(vec v, vec w) { return len2(v-w); }

vec p[8];
bool fnd = false;

bool check_cube() {
	vector<vec> v;
	FOR(i,1,8) v.pb(p[i]-p[0]);
	sort(all(v),[&](const vec &a, const vec &b) { return len2(a) < len2(b); });
	if (len2(v[0]) == 0) return false;
	if (len2(v[0]) != len2(v[1])) return false;
	if (len2(v[1]) != len2(v[2])) return false;
	if (len2(v[3]) != len2(v[4])) return false;
	if (len2(v[4]) != len2(v[5])) return false;
	FOR(i,0,3) if (v[i] % v[(i+1)%3] != 0) return false;
	if (v[0] + v[1] + v[2] != v[6]) return false;
	FOR(i,0,3) {
		vec w = v[6] - v[i];
		bool ok = false;
		FOR(j,3,6) if (v[j] == w) ok = true;
		if (!ok) return false;
	}
	return true;
}

void rec(ll i) {
	if (i < 8) {
		do rec(i+1); while (next_permutation(p[i].a,p[i].a+3));
		return;
	}
	if (check_cube()) {
		cout << "YES" << endl;
		FOR(i,0,8) FOR(j,0,3) cout << p[i].a[j] << " \n"[j == 2];
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(i,0,8) {
		FOR(j,0,3) cin >> p[i].a[j];
		sort(p[i].a,p[i].a+3);
	}
	rec(1);
	if (!fnd) cout << "NO" << endl;	
}
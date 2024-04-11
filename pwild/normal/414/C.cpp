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

ll n;
ll a[1 << 20];
ll lvl[2][20];

void init(ll p, ll i, ll j, ll l) {
	if (j-i == 1) return;
	ll k = (i+j)/2;
	init(2*p+1,i,k,l+1);
	init(2*p+2,k,j,l+1);
	{
		ll i2 = k;
		FOR(i1,i,k) {
			while (i2 < j && a[i1] > a[i2]) i2++;
			lvl[0][l] += i2-k;
		}
	}
	{
		ll i1 = i;
		FOR(i2,k,j) {
			while (i1 < k && a[i1] < a[i2]) i1++;
			lvl[1][l] += i1-i;
		}
	}
	sort(a+i,a+j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	FOR(i,0,1 << n) cin >> a[i];
	
	memset(lvl,0,sizeof(lvl));
	init(0,0,1 << n,0);
	ll m; cin >> m;
	ll cur = 0, inv = 0;
	FOR(l,0,n) inv += lvl[0][l];
	FOR(i,0,m) {
		ll q; cin >> q;
		q = n-q;
		FOR(l,q,n) {
			if (cur & (1 << l)) inv += lvl[0][l] - lvl[1][l];
			else inv -= lvl[0][l] - lvl[1][l];
			cur ^= (1 << l);
		}
		cout << inv << "\n";
	}
}
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
	
	ll N = 1e5+10;
	vb pr(N,true);
	FOR(i,2,N) if (pr[i]) for (ll j = i*i; j < N; j += i) pr[j] = false;

	ll n; cin >> n;
	if (n <= 2) {
		cout << 1 << endl;
		FOR(i,0,n) cout << 1 << " \n"[i+1==n];
	} else {
		cout << 2 << endl;
		FOR(i,0,n) cout << (pr[i+2] ? 1 : 2) << " \n"[i+1==n];
	}

}
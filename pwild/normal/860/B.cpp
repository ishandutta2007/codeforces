#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
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

const ll maxN = 2e6; //370000;
ll N = 1;
ll go[maxN][10];
ll id[maxN];

void add(string s, ll sid) {
	ll n = sz(s);
	FOR(j,0,n) {
		ll cur = 0;
		FOR(i,j,n) {
			ll x = s[i]-'0';
			if (go[cur][x] == -1) go[cur][x] = N++;
			cur = go[cur][x];
			if (id[cur] == -1 || id[cur] == sid) id[cur] = sid;
			else id[cur] = -2;
		}
	}
}

string calc(string s, ll sid) {
	ll n = sz(s);
	pll best = {0,n};
	FOR(j,0,n) {
		ll cur = 0;
		FOR(i,j,n) {
			ll x = s[i]-'0';
			if (go[cur][x] == -1) go[cur][x] = N++;
			cur = go[cur][x];
			if (id[cur] == sid && (i+1-j) < best.yy-best.xx) {
				best = {j,i+1};				
			}
		}
	}
	ll i, j;
	tie(j,i) = best;
	return s.substr(j,i-j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(go,-1,sizeof go);
	memset(id,-1,sizeof id);

	ll n; cin >> n;
	vector<string> a(n);
	FOR(i,0,n) cin >> a[i];

	if (n == 1) {
		cout << a[0][0] << endl;
		return 0;
	}
	
	FOR(i,0,n) add(a[i],i);
	
	FOR(i,0,n) cout << calc(a[i],i) << "\n";

}
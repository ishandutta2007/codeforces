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
	
	ll n, k; cin >> n >> k;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll i = 0, j = 0, cnt = 0;
	ll besti = -1, bestj = -1;

	while (i < n) {
		while (j < n && cnt < k) if (!a[j++]) cnt++;
		while (j < n && a[j] == 1) j++;
		if (j-i > bestj-besti) besti = i, bestj = j;
		if (!a[i++]) cnt--;
	}
	
	cout << bestj-besti << endl;
	FOR(i,besti,bestj) a[i] = 1;
	FOR(i,0,n) cout << a[i] << " \n"[i+1==n];



}
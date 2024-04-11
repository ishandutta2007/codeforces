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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		ll n = sz(s);
		vl x(n+1), y(n+1);
		FOR(i,0,n) {
			ll dx = (s[i] == 'W') - (s[i] == 'S');
			ll dy = (s[i] == 'A') - (s[i] == 'D');
			x[i+1] = x[i] + dx;
			y[i+1] = y[i] + dy;
		}
		n++;
		
		ll res = oo;
		FOR(rot,0,2) {
			ll height = *max_element(all(y)) - *min_element(all(y)) + 1;
			
			vl minpre = x, maxpre = x, minsuf = x, maxsuf = x;
			FOR(i,1,n) minpre[i] = min(minpre[i],minpre[i-1]);
			FOR(i,1,n) maxpre[i] = max(maxpre[i],maxpre[i-1]);
			FORD(i,0,n-1) minsuf[i] = min(minsuf[i],minsuf[i+1]);
			FORD(i,0,n-1) maxsuf[i] = max(maxsuf[i],maxsuf[i+1]);
			
			FOR(i,1,n) FOR(dx,-1,2) {
				ll xmin = min(minpre[i],minsuf[i]+dx);
				ll xmax = max(maxpre[i],maxsuf[i]+dx);
				res = min(res, (xmax-xmin+1) * height);
			}
			
			swap(x,y);
		}
		cout << res << endl;
	}
}
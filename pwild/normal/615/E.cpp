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
	
	ll n; cin >> n;
	
	if (!n) {
		cout << "0 0" << endl;
		return 0;
	}
	
	n--;

	ll sum = 0, k = 1;
	if (n > 1e12) {
		k = (-3 + sqrt(9 + 12.0*n))/6 - 100;
		sum = 3*k*(k-1);
	}	
	while (n >= sum + 6*k) sum += 6*k, k++;
	n -= sum;
	
	ll x = k, y = 0;
	if (n != 6*k-1) {
		n++;
		ll dx[] = {-1,-1,0,1,1,0}, dy[] = {1,0,-1,-1,0,1};
		FOR(i,0,n/k+1) {
			ll len = k;
			if ((i+1)*k >= n) len = n - i*k;
			x += len*dx[i], y += len*dy[i];
		}	
	}
	
	tie(x,y) = pll(2*x + y,2*y);
	cout << x << " " << y << endl;


}
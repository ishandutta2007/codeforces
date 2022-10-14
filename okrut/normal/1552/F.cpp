#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;
const int N = 2e5+10;
ll T[N], Pref[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	
	vector <pair <int, int> > portals(n);
	vector <bool> active(n);
	vector <ll> time, pref;
	
	rep(i,0,n) {
		int x;
		scanf ("%d %d %d", &portals[i].fi, &portals[i].se, &x);
		active[i] = (x == 1);
	}
	
	T[0] = portals[0].fi - portals[0].se;
	Pref[1] = T[0];
	
	rep(i,1,n) {
		
		int land = upper_bound(portals.begin(), portals.end(), make_pair(portals[i].se, 0)) - portals.begin();
		
		T[i] = ll(portals[i].fi - portals[i].se) + mod + Pref[i] - Pref[land];
		Pref[i+1] = (Pref[i] + T[i]) % mod;
	}
	
	
	ll res = portals[n-1].fi + 1;
	
	rep(i,0,n) if (active[i]) res += T[i];
	
	res %= mod;
	printf ("%lld\n", res);
}
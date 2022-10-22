#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;

ll solve(ll x) {
	if (x == 0) return 0;
	ll y = sqrt(x);

	ll ans = (y-1) * 3 + 1;
	
	if (x >= y * (y+1)) ans++;
	if (x >= y*y + 2*y) ans++;
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << solve(m) - solve(n-1) << nl;
	}
}
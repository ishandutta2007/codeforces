#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

bool prime[5005];
void calcPrime() {
	FOR(i, 2, 5005) {
		for(int j = i*i; j < 5005; j += i) prime[j] = true;
	}
}
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	if(n == 3) {
		cout << 3 << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "3 1" << endl;
		return 0;
	}
	calcPrime();
	vector<pii> v;
	F0R(i, n/4-1) {
		v.pb(mp(4*i, 4*i+1));
		v.pb(mp(4*i+1, 4*i+2));
		v.pb(mp(4*i+2, 4*i+3));
		v.pb(mp(4*i+3, 4*i));
	}
	FOR(i, (n/4-1)*4, n-1)
		v.pb(mp(i, i+1));
	v.pb(mp(n-1, (n/4-1)*4));
	int cur = 0;
	while(cur+2 < n && prime[v.size()]) {
		v.pb(mp(cur, cur+2));
		if(cur % 4 == 0) cur++;
		else cur+=3;
	}
	if(prime[v.size()]) cout << -1 << endl;
	else {
		cout << v.size() << endl;
		for(auto x : v) cout << x.f+1 << " " << x.s+1 << endl;
	}
///
	return 0;
}
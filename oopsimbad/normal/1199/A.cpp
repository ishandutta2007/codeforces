#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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

///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, x, y; cin >> n >> x >> y;
	vi v;
	F0R(i, n) {
		int a; cin >> a;
		v.pb(a);
	}
	F0R(i, n) {
		bool b = true;
		FOR(j, max(0,i-x),i) b &= v[j] > v[i];
		FOR(j, i+1,min(n,i+y+1)) b &= v[j] > v[i];
		if(b) {
			cout << i+1 << endl;
			break;
		}
	}
///
	cin >> n;
	return 0;
}
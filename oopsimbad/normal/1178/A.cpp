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

const int MAXN = 105;

///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, sum1, sum2, max; cin >> n >> max;
	sum1 = max;
	sum2 = max;
	vi v; v.pb(0);
	F0R(i, n-1) {
		int a; cin >> a;
		if(a*2 <= max) {
			sum1 += a;
			v.pb(i+1);
		}
		sum2 += a;
	}
	if(sum1*2 <= sum2) cout << 0 << endl;
	else {
		cout << v.size() << endl;
		for(auto x : v) cout << x+1 << " ";
		cout << endl;
	}
///
	return 0;
}
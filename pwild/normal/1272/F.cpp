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

string a, b;

const ll N = 210;
ll dp[N][N][N], m, n;

ll rec(ll i, ll j, ll d) {
	if (d < 0 || d >= N) return oo;
	if (i == m && j == n) return d;

	ll &res = dp[i][j][d];
	if (res != -1) return res;
	
	res = oo;
	for (char c: {'(',')'}) {
		ll ni = i + (i < m && a[i] == c);
		ll nj = j + (j < n && b[j] == c);
		ll nd = d + (c == '(' ? 1 : -1);
		res = min(res, 1 + rec(ni,nj,nd));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b;
	memset(dp,-1,sizeof dp);
	m = sz(a), n = sz(b);
	
	ll i = 0, j = 0, d = 0;
	
	string res;
	while (i < m || j < n) {
		// cerr << i << " " << j << " " << d << " " << rec(i,j,d) << endl;
		for (char c: {'(',')'}) {
			ll ni = i + (i < m && a[i] == c);
			ll nj = j + (j < n && b[j] == c);
			ll nd = d + (c == '(' ? 1 : -1);
			if (rec(i,j,d) == 1 + rec(ni,nj,nd)) {
				res += c, i = ni, j = nj, d = nd;
				break;
			}
		}
	}
	res += string(d,')');
	cout << res << endl;
}
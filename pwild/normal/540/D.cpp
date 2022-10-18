#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll N = 101;

double dp[N][N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll R, S, P; cin >> R >> S >> P;
	
	FOR(r,0,N) FOR(s,0,N) FOR(p,0,N) {
		dp[r][s][p] = 0;
		ll cnt = r+s+p;
		if (cnt == 0) continue;
		if (cnt == r) {
			dp[r][s][p] = 1;
			continue;
		}
		if (cnt == s || cnt == p || cnt < 2) continue;

		double rs = double(2*r*s)/cnt;
		double rp = double(2*r*p)/cnt;
		double sp = double(2*s*p)/cnt;
		double sum = rs+rp+sp;
		rs /= sum, rp /= sum, sp /= sum;
		if (r > 0) dp[r][s][p] += rp*dp[r-1][s][p];
		if (s > 0) dp[r][s][p] += rs*dp[r][s-1][p];
		if (p > 0) dp[r][s][p] += sp*dp[r][s][p-1];
	}

	cout << fixed << setprecision(12);
	cout << dp[R][S][P] << " " << dp[S][P][R] << " " << dp[P][R][S] << endl;

}
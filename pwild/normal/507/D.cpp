#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll dp[1005][10][105];
ll tp[1005];


int main() {
	ios_base::sync_with_stdio(false);

	ll N,K,M; cin >> N >> K >> M;
	
	tp[0] = 1;
	FOR(i,1,N+1) tp[i] = (10*tp[i-1]) % M;
	
	memset(dp,0,sizeof(dp));
	FOR(j,0,10) dp[1][j][j%K]++;
	ll t = 10;
	ll res = 0;
	FOR(i,1,N+1) {
		ll fac = (i == N) ? 1 : 9*tp[N-i-1]; fac %= M;
		res += fac*(dp[i][0][0]-1);
		FOR(j,1,10) {
			res += fac*dp[i][j][0];
			res %= M;
			dp[i][j][0] = 0;
		}
		if (i == N) break;
		FOR(d,0,10) FOR(j,0,10) FOR(k,0,K) {
			dp[i+1][d][(k+d*t)%K] += dp[i][j][k];
			dp[i+1][d][(k+d*t)%K] %= M;
		}
		t = (10*t) % K;
	}
	cout << res << endl;
	/*
	ll res = 0;
	FOR(i,1,N+1) {
		FOR(j,1,10) res += fac*dp[N][j][0];
		res %= M;
	}
	cout << res << endl;
	*/
}
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

ll dp[100005];
ll dpsum[100005];
const ll MOD = 1000000007;
bool app[100005];

int main() {
	ios_base::sync_with_stdio(false);

	string pattern, text;
	cin >> text >> pattern;
	int P = sz(pattern), T = sz(text);
	vi prefix(P);
	int m = prefix[0] = 0;
	FOR(i,1,P) {
		while (m > 0 && pattern[m] != pattern[i]) m = prefix[m-1];
		if (pattern[m] == pattern[i]) m++;
		prefix[i] = m;
	}
	m = 0;
	memset(app,false,sizeof(app));
	FOR(i,0,T) {
		while (m > 0 && pattern[m] != text[i]) m = prefix[m-1];
		if (pattern[m] == text[i]) m++;
		if (m == P) {
			app[i-m+1] = true;		
			m = prefix[m-1];
		}
	}
	
	dp[0] = dpsum[0] = 1;
	int last = 0;
	FOR(i,1,T+1) {
		dp[i] = dp[i-1];
		if (i >= P && app[i-P]) {
			last = i;
			dp[i] += dpsum[i-P];	
		} else if (last >= P) {
			dp[i] += dpsum[last-P];
		}
		dp[i] %= MOD;
		dpsum[i] = (dpsum[i-1] + dp[i]) % MOD;
	}
	
//	FOR(i,0,T+1) cerr << app[i] <<" " << dp[i] << " " << dpsum[i] << endl;


	ll res = (dp[T] + MOD - 1) % MOD;
	cout << res << endl;



}
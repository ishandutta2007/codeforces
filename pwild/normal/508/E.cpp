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
#define xx first
#define yy second

const int maxN = 610;

pii v[maxN];
int dp[maxN][maxN];

bool rec(int a, int b) {
	if (a >= b) return true;
	if (dp[a][b] >= 0) return dp[a][b];
	FOR(i,0,b-a) {
		int len = 2*(b-a-i) - 1;
		if (v[a].xx <= len && len <= v[a].yy && rec(a+1,b-i) && rec(b-i,b)) {
			dp[a][b] = len;		
			return true;
		}
	}
	dp[a][b] = 0;
	return false;
}

string res;

void rec2(int a, int b, int c) {
	if (a >= b) return;
	res[c] = '(';
	int len = dp[a][b];
	res[c+len] = ')';
	int i = b-a-(len+1)/2;
	rec2(a+1,b-i,c+1);
	rec2(b-i,b,c+len+1);
}


int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	FOR(i,0,n) cin >> v[i].xx >> v[i].yy;
	
	memset(dp,-1,sizeof(dp));
	
	if (rec(0,n)) {
		res = string(2*n,' ');
		rec2(0,n,0);
		cout << res << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}

}
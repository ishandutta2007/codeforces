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

string s[105];

bool adj[26][26];
int indeg[26];
vi res;

int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	FOR(i,0,n) cin >> s[i];

	memset(adj,0,sizeof(adj));

	FOR(i,0,n) FOR(j,i+1,n) {
		int k = 0;
		for (; k < sz(s[i]) && k < sz(s[j]); k++) if (s[i][k] != s[j][k]) break;
		if (k == sz(s[j])) {
			cout << "Impossible" << endl;
			return 0;
		}
		if (k == sz(s[i])) continue;
		adj[s[i][k]-'a'][s[j][k]-'a'] = true;

	}
	
	memset(indeg,0,sizeof(indeg));
	FOR(i, 0, 26) FOR(j, 0, 26) if (adj[i][j]) indeg[j]++;
	stack<int> zero;
	FOR(i, 0, 26) if (indeg[i] == 0) zero.push(i);
	while (!zero.empty()) {
		int i = zero.top();
		zero.pop();
		res.pb(i);
		FOR(j, 0, 26) {
			if (adj[i][j] && --indeg[j] == 0) zero.push(j);
		}
	}
	if (sz(res) != 26) {
		cout << "Impossible" << endl;
	} else {
		FOR(i,0,26) cout << char('a'+res[i]);
		cout << endl;

	}
}
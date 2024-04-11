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

int c2i(char c) {
	if ('0' <= c && c <= '9') return c-'0';
	if ('A' <= c && c <= 'Z') return 10+c-'A';
	return 36+c-'a';
}

char i2c(int i) {
	if (i < 10) return '0'+i;
	if (i < 36) return 'A'+i-10;
	return 'a'+i-36;
}

const int N = 62*62;
vi adj[N], path;
int pos[N], indeg[N];

void rek(int n) {
	while (pos[n] < sz(adj[n])) rek(adj[n][pos[n]++]);
	path.pb(n);
}

bool euler_path() {

	FOR(i,0,N) pos[i] = indeg[i] = 0;
	FOR(i,0,N) FOR(j,0,sz(adj[i])) indeg[adj[i][j]]++;
	int src = -1, tgt = -1;
	FOR(i,0,N) {
		if (abs(sz(adj[i]) - indeg[i]) >= 2) return false;
		if (sz(adj[i]) > indeg[i]) {
			if (src == -1) src = i; else return false;
		}
		if (sz(adj[i]) < indeg[i]) {
			if (tgt == -1) tgt = i; else return false;
		}
	}
	if (src == -1 && tgt != -1) return false;
	if (tgt == -1 && src != -1) return false;
	if (src == -1) FOR(i,0,N) if (sz(adj[i])) src = i;
	if (src == -1) return true;
	rek(src);
	reverse(all(path));
	return sz(path) == accumulate(indeg, indeg+N,0) + 1;

}


int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	FOR(i,0,n) {
		string s; cin >> s;
		int a = 62*c2i(s[0]) + c2i(s[1]);
		int b = 62*c2i(s[1]) + c2i(s[2]);
		adj[a].pb(b);
	}
	
	if (euler_path()) {
		cout << "YES" << endl;
		cout << i2c(path[0]/62);
		for (const int &k: path) cout << i2c(k%62);
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

}
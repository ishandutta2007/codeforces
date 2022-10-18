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
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })
#define xx first
#define yy second

const int maxN = 2010;
char a[maxN][maxN];
ll nb[maxN][maxN];

string fail = "Not unique";

int main() {
	ios_base::sync_with_stdio(false);

	ll r, c; cin >> r >> c;
	
	FOR(i,0,r+2) a[i][0] = a[i][c+1] = '*';
	FOR(j,0,c+2) a[0][j] = a[r+1][j] = '*';
	FOR(i,1,r+1) FOR(j,1,c+1) cin >> a[i][j];
	
	ll di[] = {0,0,1,-1}, dj[] = {1,-1,0,0};
	string cp = "<>^v", np = "><v^";

	queue<pii> q;

	FOR(i,1,r+1) FOR(j,1,c+1) {
		if (a[i][j] == '.') {
			nb[i][j] = 0;
			FOR(k,0,4) if (a[i+di[k]][j+dj[k]] == '.') nb[i][j]++;
			if (nb[i][j] == 0) {
				cout << fail << endl;
				return 0;
			}
			if (nb[i][j] == 1) q.emplace(i,j);
		}
	}

	while (sz(q)) {
		ll ci, cj;
		tie(ci,cj) = q.front(); q.pop();
		if (a[ci][cj] != '.') continue;
		bool ok = false;
		FOR(k,0,4) {
			ll ni = ci+di[k], nj = cj + dj[k];
			if (a[ni][nj] != '.') continue;
			ok = true;
			a[ci][cj] = cp[k];
			a[ni][nj] = np[k];
//			cerr << ci << " " << cj << " " << ni << " " << nj << endl;	
			FOR(l,0,4) {
				ll nni = ni+di[l], nnj = nj + dj[l];
				if (a[nni][nnj] == '*') continue;
				if (--nb[nni][nnj] == 1) q.emplace(nni,nnj); 
			}
			break;
		}
		if (!ok) {
			cout << fail << endl;
			return 0;
		}
	}

	FOR(i,1,r+1) FOR(j,1,c+1) if (a[i][j] == '.') {
		cout << fail << endl;
		return 0;
	}

	FOR(i,1,r+1) {
		FOR(j,1,c+1) {
			cout << a[i][j];
		}
		cout << endl;
	}


}
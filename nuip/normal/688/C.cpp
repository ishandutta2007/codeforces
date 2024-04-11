// Standard I/O
#include <iostream>
#include <sstream>
#include <cstdio>
// Standard Library
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
// Template Class
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
// Container Control
#include <algorithm>

using namespace std;

#define rep( i, n ) for( int i = 0; i < n; ++i )
#define irep( i, n ) for( int i = n-1; i >= 0; --i )
#define reep( i, s, n ) for ( int i = s; i < n; ++i )
#define ireep( i, n, s ) for ( int i = n-1; i >= s; --i )
#define foreach(itr, x) for( typeof(x.begin()) itr = x.begin(); itr != x.end(); ++itr)

#define mp( a, b ) make_pair( a, b )
#define pb( a ) push_back( a )
#define all( v ) v.begin(), v.end()
#define fs first
#define sc second
#define vc vector

typedef long long ll;
typedef complex<double> Point;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;
typedef vector< vector<double> > vdd;

typedef vector<int>::iterator vi_itr;

const int IINF = 1 << 28;
const double INF = 1e30;
const double EPS = 1e-10;
const double PI = acos(-1.0);

// Direction : L U R D
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, -1, 0, 1 };

vector<int> G[100010];
int color[100010];

bool dfs(int cur, int prev, int col) {
	color[cur] = col;
	rep(i, G[cur].size()) {
		int next = G[cur][i];
		if(next != prev) {
			if(color[next] != 0) {
				if(color[next] != -col) return false;
			} else {
				if(!dfs(next, cur, -col)) return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	bool ok = true;
	rep(i, n) {
		if(!color[i]) {
			if(!dfs(i, -1, 1)) ok = false;
		}
	}
	if(ok) {
		vector<int> A, B;
#if 1
		rep(i, n) {
			if(color[i] == 1) A.pb(i + 1);
			else B.pb(i + 1);
		}
#endif
		cout << A.size() << endl;
		rep(i, A.size()) {
			if(i != A.size() - 1) cout << A[i] << " ";
			else cout << A[i] << endl;
		}
		cout << B.size() << endl;
		rep(i, B.size()) {
			if(i != B.size() - 1) cout << B[i] << " ";
			else cout << B[i] << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
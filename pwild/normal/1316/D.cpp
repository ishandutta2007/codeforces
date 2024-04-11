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

void fail() {
	cout << "INVALID" << endl;
	exit(0);
}

const ll N = 1010;
pll a[N][N];
vector<pll> comp[N][N];
char sol[N][N];

ll n;

void rec(ll i, ll j) {
	FOR(di,-1,2) FOR(dj,-1,2) if (abs(di)+abs(dj) == 1) {
		ll ni = i+di, nj = j+dj;
		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		if (a[ni][nj] != a[i][j]) continue;
		if (sol[ni][nj]) continue;
		if (di > 0) sol[ni][nj] = 'U';
		if (di < 0) sol[ni][nj] = 'D';
		if (dj > 0) sol[ni][nj] = 'L';
		if (dj < 0) sol[ni][nj] = 'R';
		rec(ni,nj);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	memset(a,0x3f,sizeof a);
	
	FOR(i,0,n) FOR(j,0,n) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		a[i][j] = {x,y};
		if (x >= 0) comp[x][y].eb(i,j);
	}
	
	FOR(i,0,n) FOR(j,0,n) if (!sol[i][j]) {
		if (a[i][j].xx < 0) {
			if (a[i+1][j] == a[i][j]) {
				sol[i][j] = 'D', sol[i+1][j] = 'U';
				rec(i,j), rec(i+1,j);
			} else if (a[i][j+1] == a[i][j]) {
				sol[i][j] = 'R', sol[i][j+1] = 'L';
				rec(i,j), rec(i,j+1);
			} else {
				fail();
			}
		} else {
			auto [ni,nj] = a[i][j];
			if (a[ni][nj] != a[i][j]) fail();
			sol[ni][nj] = 'X';
			rec(ni,nj);
			if (!sol[i][j]) fail();
		}
	}
	
	cout << "VALID" << endl;
	FOR(i,0,n) {
		FOR(j,0,n) cout << sol[i][j];
		cout << endl;
	}
}
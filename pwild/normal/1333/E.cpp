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

ll sim(vvl a, bool isq) {
	ll n = sz(a), x = 100, y = 30;
	
	ll res = -1;
	FOR(k,0,n*n) {
		ll nx = -1, ny = -1;
		FOR(i,0,n) FOR(j,0,n) {
			bool ok = i == x || j == y;
			if (isq) ok = ok || i-j == x-y || i+j == x+y;
			if (!ok) continue;
			if (nx == -1 || a[i][j] < a[nx][ny]) nx = i, ny = j;
		}
		x = nx, y = ny;
		if (x == -1 || a[x][y] == oo) {
			ll cur = oo;
			FOR(i,0,n) FOR(j,0,n) if (a[i][j] < cur) {
				x = i, y = j, cur = a[i][j];
			}
			res++;
		}
		a[x][y] = oo;
	}
	return res;
}

void brute() {
	vvl test = {{4,3,6,12},{7,5,9,15},{14,1,11,10},{13,8,16,2}};
	
	FOR(n,2,5) {
		vl p(n*n);
		iota(all(p),0);
		do {
			vvl a(n, vl(n));
			FOR(i,0,n) FOR(j,0,n) a[i][j] = p[n*i+j];
			if (sim(a,0) < sim(a,1)) {
				FOR(i,0,n) FOR(j,0,n) cout << a[i][j] << " \n"[j+1==n];
				break;
			}
		} while (next_permutation(all(p)));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vvl a = {{0,1,3},{4,2,7},{8,5,6}};
	
	ll n; cin >> n;
	if (n <= 2) {
		cout << -1 << endl;
	} else {
		vvl res(n,vl(n));
		FOR(i,0,3) FOR(j,0,3) res[i][j] = n*n-8 + a[i][j];
		ll k = n*n-9;
		FOR(i,0,n) {
			ll jmin = i < 3 ? 3 : 0;
			if (i%2 == 0) FOR(j,jmin,n) res[i][j] = k--;
			else FORD(j,jmin,n) res[i][j] = k--;
		}
		FOR(i,0,n) FOR(j,0,n) cout << res[i][j] << " \n"[j+1==n];
	}
}
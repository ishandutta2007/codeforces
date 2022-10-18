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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll maxN = 2005;

ll gId[maxN][maxN], gInd[maxN][maxN];
vl gSum[maxN];
ll sx[maxN], sy[maxN];

int main() {
	ll m, n, k;
	scanf("%lld %lld %lld\n",&m,&n,&k);
	FOR(i,1,k+1) {
		ll len;
		scanf("%lld\n",&len);
		gSum[i].resize(len+1);
		FOR(j,0,len) {
			ll x, y, w;
			scanf("%lld %lld %lld\n",&x,&y,&w);
			gId[x][y] = i, gInd[x][y] = j;
			gSum[i][j+1] = gSum[i][j] + w;
			if (j == 0) sx[i] = x, sy[i] = y;
		}
	}
	vb act(k+1,true);
	ll q;
	scanf("%lld\n",&q);
	while (q--) {
		char s[10];
		scanf("%s",s);
		if (s[0] == 'A') {
			ll x1, y1, x2, y2;
			scanf("%lld %lld %lld %lld\n",&x1,&y1,&x2,&y2);
			vvl ev(k+1);
			FOR(i,1,k+1)
				if (x1 <= sx[i] && sx[i] <= x2 && y1 <= sy[i] && sy[i] <= y2)
					ev[i].pb(0);
			
			auto check_nb = [&](ll i1, ll j1, ll i2, ll j2) {
				if (gId[i1][j1] == gId[i2][j2] && abs(gInd[i1][j1] - gInd[i2][j2]) == 1)
					ev[gId[i1][j1]].pb(max(gInd[i1][j1],gInd[i2][j2]));
			};
			FOR(x,x1,x2+1) check_nb(x,y1-1,x,y1), check_nb(x,y2,x,y2+1);
			FOR(y,y1,y2+1) check_nb(x1-1,y,x1,y), check_nb(x2,y,x2+1,y);
			
			ll res = 0;
			FOR(i,1,k+1) if (act[i]) {
				if (sz(ev[i]) % 2) ev[i].pb(sz(gSum[i])-1);
				sort(all(ev[i]));
				for (ll j = 0; j < sz(ev[i]); j += 2)
					res += gSum[i][ev[i][j+1]] - gSum[i][ev[i][j]];
			}
			cout << res << endl;
		} else {
			ll i;
			scanf("%lld\n",&i);
			act[i] = !act[i];
		}
	}
}
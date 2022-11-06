#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
const int MAXN = 1005;
const ll MOD = 998244353LL;
int len[MAXN];
vector<pii> v[MAXN];
ll mat[3][64][64];
ll pows[32][64][64];
ll dp[MAXN][4];
void calc(int n, bool a, bool b, bool c) {
	F0R(i, 4)
		F0R(j, 4)
			F0R(k, 4)
				F0R(r, 4)
					if(!(i == r && c || j == r && b || k == r && a)) {
						mat[n][i<<4|j<<2|k][j<<4|k<<2|r] = 1;
						break;
					}

}
///
int main() {
	memset(mat, 0, sizeof(mat));
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	F0R(i, n) cin >> len[i];
	int m; cin >> m;
	F0R(i, m) {
		int x, y, c; cin >> x >> y >> c;
		v[x-1].pb(mp(y,c-1));
	}
	F0R(i, 3) {
		int a, b, c; cin >> a >> b >> c;
		calc(i, a, b, c);
	}
	F0R(i, 64)
		F0R(j, 64)
			pows[0][i][j] = mat[0][i][j] + mat[1][i][j] + mat[2][i][j];
	FOR(p, 1, 32)	
		F0R(i, 64)
			F0R(j, 64)
				F0R(k, 64) 
					pows[p][i][k] = (pows[p][i][k] + pows[p-1][i][j]*pows[p-1][j][k]%MOD)%MOD;
	F0R(asdf, n) {
		ll cur[64], aux[64];
		memset(cur, 0, sizeof(cur));
		memset(aux, 0, sizeof(aux));
		memset(dp[asdf], 0, sizeof(dp[asdf]));
		cur[63] = 1;
		int curi = 0;
		sort(v[asdf].begin(), v[asdf].end());
		for(auto x : v[asdf]) {
			int diff = x.f-curi-1;
			int pow = 0;
			while(diff > 0) {
				if(diff % 2 == 1) {
					F0R(i, 64)
						F0R(j, 64)
							aux[j] = (aux[j]+cur[i]*pows[pow][i][j]%MOD)%MOD;	
					F0R(i, 64) {
						cur[i] = aux[i];
						aux[i] = 0;
					}
				}
				diff /= 2;
				pow++;
			}
			F0R(i, 64)
				F0R(j, 64)
					aux[j] = (aux[j]+cur[i]*mat[x.s][i][j]%MOD)%MOD;
			F0R(i, 64) {
				cur[i] = aux[i];
				aux[i] = 0;
			}
			curi = x.f;
		}
		int diff = len[asdf]-curi;
		int pow = 0;
		while(diff > 0) {
			if(diff % 2 == 1) {
				F0R(i, 64)
					F0R(j, 64)
						aux[j] = (aux[j]+cur[i]*pows[pow][i][j]%MOD)%MOD;	
				F0R(i, 64) {
					cur[i] = aux[i];
					aux[i] = 0;
				}
			}
			diff /= 2;
			pow++;
		}
		F0R(i, 64) {
			dp[asdf][i&3] = (dp[asdf][i&3]+cur[i])%MOD;
		}
	}
	ll ans[4];
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	F0R(a, n) {
		ll nx[4];
		memset(nx, 0, sizeof(nx));
		F0R(i, 4)
			F0R(j, 4)
				nx[i^j] = (nx[i^j] + ans[i]*dp[a][j]%MOD)%MOD;
		F0R(i, 4) ans[i] = nx[i];
	}
	cout << ans[0] << endl;
///
	//cin >> n;
	return 0;
}
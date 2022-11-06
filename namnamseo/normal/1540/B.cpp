#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
template<typename T,typename U>
istream& operator>>(istream& i, pair<T,U>& p) { i >> p.first >> p.second; return i; }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()
#define XY(t) t.x, t.y

const int maxn = 210;

int n;
vector<int> e[maxn];

const ll mod = int(1e9) + 7;
const ll half = (mod+1) / 2;

ll F(int l, int r) {
	if (!l) { return 1; }
	if (!r) { return 0; }

	if (l < 0 || r < 0) return 0;

	static ll dp[maxn][maxn];
	ll &ret = dp[l][r];
	if (ret) return ret;

	ret = half * (F(l-1, r) + F(l, r-1)) % mod;
	return ret;
}

int dst[maxn][maxn];

int par[maxn];

void Dfs(int x, int p=0) {
	for (int y:e[x]) if (y != p) {
		par[y] = x;
		Dfs(y, x);
	}
}

ll minv(ll b) {
	ll r=1, e=mod-2;
	while (e) {
		if (e&1) (r*=b)%=mod;
		(b*=b)%=mod; e>>=1;
	}
	return r;
}

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) rrep(j, n) if (i!=j) dst[i][j] = n*2;

	for (int i=1; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].pb(b); e[b].pb(a);
		dst[a][b] = dst[b][a] = 1;
	}

	rrep(j, n) rrep(i, n) rrep(k, n) {
		dst[i][k] = min(dst[i][k], dst[i][j] + dst[j][k]);
	}

	ll ans = 0;
	rrep(i, n) {
		//Dfs(i);
		for (int j=i+1; j<=n; ++j) {
			int ij = dst[i][j];

			rrep(k, n) {
				int di = dst[k][i], dj = dst[k][j];
				if (di + ij == dj) {
					// no inversion
				} else if (di == ij + dj) {
					ans += 1;
					if (ans >= mod) ans -= mod;
				} else {
					int t = (di + dj - ij) / 2;
					ans += F(dj-t, di-t);
					if (ans >= mod) ans -= mod;
				}
			}
		}
	}

	ans = ans * minv(n) % mod;

	cout << ans << '\n';

	return 0;
}
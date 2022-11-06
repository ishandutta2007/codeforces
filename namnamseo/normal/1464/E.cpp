#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(1e5) + 10;
const ll mod = 998'244'353;

ll ipow(ll b, ll e) {
	ll ret = 1;
	while (e) {
		if (e&1) (ret *= b) %= mod;
		e/=2; (b*=b)%=mod;
	}
	return ret;
}

int n, m;

vector<int> e[maxn];
bitset<maxn> vis;

int hist[maxn], hn;
void dfs(int x) {
	vis[x] = 1;
	for (int y:e[x]) if (!vis[y]) dfs(y);
	hist[hn++] = x;
}

int grd[maxn];

int mat[512][512];
int gc[512];
int av[512];

int main()
{
	cppio();

	cin >> n >> m;
	rrep(i, m) {
		int a, b; cin >> a >> b; e[a].pb(b);
	}

	rrep(i, n) if (!vis[i]) dfs(i);
	rep(hi, hn) {
		int x = hist[hi];
		static bitset<512> mex;
		mex.reset();
		for (int y:e[x]) mex.set(grd[y]);
		for (int j=0;;++j) {
			if (j == 512 || !mex[j]) {
				grd[x] = j;
				++gc[j];
				break;
			}
		}
	}

	rep(i, 512) mat[i][i] = 1;
	av[0] = 1;

	int np1i = ipow(n+1, mod-2);
	int mnp1i = mod - np1i;

	rep(i, 512) {
		rep(j, 512) {
			int v = i ^ j;
			(mat[i][j] += mnp1i * 1ll * gc[v] % mod) %= mod;
		}
	}

	rep(i, 512) {
		{ int r = i;
		for(int j=i; j<512; ++j) if (mat[j][i]) {
			r = j; break;
		}

		if (r!=i) {
			for(int j=i; j<512; ++j) {
				swap(mat[r][j], mat[i][j]);
			}
			swap(av[r], av[i]);
		} }

		ll c = ipow(mat[i][i], mod-2);
		for(int j=i; j<512; ++j) {
			mat[i][j] = mat[i][j] * c % mod;
		}
		av[i] = (av[i] * c % mod);

		rep(j, 512) if (j!=i) {
			ll cc = mat[j][i];
			if (!cc) continue;
			cc = mod-cc;
			for(int k=i; k<512; ++k) {
				(mat[j][k] += mat[i][k] * cc % mod) %= mod;
			}
			(av[j] += av[i] * cc % mod) %= mod;
		}
	}

	ll ans = mod + 1 - np1i * 1ll * av[0] % mod;
	ans %= mod;
	cout << ans << '\n';

	return 0;
}
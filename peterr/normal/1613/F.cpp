#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

const int MAXN = 250000;
vector<int> adjList[MAXN + 1];
int children[MAXN + 1];
int fac[MAXN + 1];

void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}

void dfs(int v, int p)
{
	for (int adj : adjList[v])
	{
		if (adj == p)
			continue;
		dfs(adj, v);
		children[v]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		fac[i] = (int) ((long long) fac[i - 1] * i % mod);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	dfs(1, 1);
	deque<vl> poly;
	for (int i = 1; i <= n; i++)
	{
		if (children[i])
			poly.push_back({1, children[i]});
	}
	while (poly.size() >= 2)
	{
		vl first = poly.front();
		poly.pop_front();
		vl second = poly.front();
		poly.pop_front();
		poly.push_back(conv(first, second));
	}
	//cout << "size " << poly[0].size() << "\n";
	int ans = 0;
	for (int i = 0; i < (int) poly[0].size(); i++)
	{
		if (i > n)
			break;
		//cout << "poly " << i << " " << poly[0][i] << "\n";
		int ways = (int) ((long long) poly[0][i] * fac[n - i] % mod);
		if (i & 1)
			add(ans, mod - ways);
		else
			add(ans, ways);
		//cout << ans << endl;
	}
	cout << ans << "\n";
	return 0;
}
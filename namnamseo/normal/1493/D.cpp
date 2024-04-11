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

#define plus Plus
#define prev Prev

const int maxn = int(2e5) + 10;
const int B = 87;

int n, q;

int pr[18000], prn;
int prev[maxn];
bitset<100001> pm;
void build_prime() {
	pr[prn++] = 2;
	for(long long i=3; i<=int(2e5); i+=2) {
		if (pm[(i+1)/2]) continue;
		pr[prn++] = i;
		for (auto j=i*i; j<=int(2e5); j+=2*i) {
			pm[(j+1)/2] = 1;
		}
	}
	rep(i, prn) prev[pr[i]] = i;
}

const int M = 262144;

vector<pp> digest(int x) {
	vector<pp> ret;
	int tc = 0;
	while (x%2 == 0) {
		++tc; x/=2;
	}
	if (tc) ret.eb(0, tc);

	int pi = 1;
	while (x > 1) {
		if (!pm[(x+1)/2]) {
			ret.eb(prev[x], 1);
			break;
		}
		while (x%pr[pi]) ++pi;
		int cnt = 0;
		while (x%pr[pi] == 0) {
			++cnt;
			x /= pr[pi];
		}
		ret.eb(pi, cnt);
	}

	return ret;
}

const ll mod = int(1e9) + 7;

int ipow(ll b, int e) {
	ll ret = 1;
	while (e) {
		if (e%2 == 1) (ret *= b) %= mod;
		(b *= b) %= mod;
		e /= 2;
	}
	return ret;
}

int tree[B+1][M<<1];

int a[maxn];

int mm;

const int inf = int(1e9);

void tupd(int bi, int p, int v) {
	tree[bi][p+=mm] += v;
	for (p/=2; p; p/=2) tree[bi][p] = min(tree[bi][p*2], tree[bi][p*2+1]);
}

int aa[maxn];
int bc[18000];

vector<int> each[18000];
vector<pp> qe[18000];

int main()
{
	cppio(); build_prime();

	cin >> n >> q;

	mm = 1;
	while (mm < n+1) mm *= 2;
	rep(i, B) {
		for (int j=n+1; j<mm; ++j) tree[i][mm+j] = inf;
		tree[i][mm] = inf;
		for (int j=mm-1; 1<=j; --j) {
			tree[i][j] = min(tree[i][j*2], tree[i][j*2+1]);
		}
	}

	rrep(i, n) {
		int x; cin >> x;
		for (auto pe:digest(x)) {
			if (pe.x < B) {
				tupd(pe.x, i, pe.y);
			} else {
				++bc[pe.x];
				each[pe.x].pb(i);
			}
		}
	}

	ll ans = 1;
	rep(i, B) if (tree[i][1] != 0) {
		ans = ans * ipow(pr[i], tree[i][1]) % mod;
	}

	rrep(_, q) {
		int qi, qx; cin >> qi >> qx;
		for (auto pe:digest(qx)) {
			if (pe.x < B) {
				ll bt = tree[pe.x][1];
				tupd(pe.x, qi, pe.y);
				ll at = tree[pe.x][1];
				if (bt == at) continue;
				ans = ans * ipow(pr[pe.x], at-bt) % mod;
			} else {
				++bc[pe.x];
				qe[pe.x].eb(_, qi);
			}
		}
		aa[_] = ans;
	}

	static int qpref[maxn];
	fill(qpref+1, qpref+q+1, 1);

	for (int i=B; i<prn; ++i) if (bc[i] >= n) {
		{
			for (int j=1; j<=n; ++j) tree[B][mm+j] = 0;
			for (int j=n+1; j<mm; ++j) tree[B][mm+j] = inf;
			tree[B][mm] = inf;
			for (int j=mm-1; 1<=j; --j) {
				tree[B][j] = min(tree[B][j*2], tree[B][j*2+1]);
			}
		}

		for (int bi:each[i]) tupd(B, bi, +1);

		int ca = tree[B][1];
		if (ca) qpref[1] = qpref[1] * 1ll * pr[i] % mod;

		for (auto &tmp:qe[i]) {
			tupd(B, tmp.y, +1);
			int na = tree[B][1];
			if (ca == na) continue;
			qpref[tmp.x] = qpref[tmp.x] * 1ll * ipow(pr[i], na-ca) % mod;
			ca = na;
		}
	}

	ll cc = 1;
	rrep(i, q) {
		(cc *= qpref[i]) %= mod;
		cout << (aa[i] * cc % mod) << '\n';
	}

	return 0;
}
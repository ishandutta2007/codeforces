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

const int maxn = int(2e5) + 10;

int n;
int a[maxn];
int h[maxn];

vector<int> e[maxn];

ll dp[maxn][3];
bool chk[maxn][3];

int par[maxn];
void dfs(int x) { for(int y:e[x]) if (y != par[x]) par[y]=x, dfs(y); }

ll f(int v, int type)
{
	ll &ret = dp[v][type];
	if (type<2 && chk[v][type]) return ret;
	chk[v][type] = 1;

	int ci=0, co=0;
	if (type == 0) ++co;
	if (type == 1) ++ci;

	vector<ll> omi;
	ll is=0, cc=0, tmp=0;

	for(int y:e[v]) if (par[y]==v) {
		if (h[y]<h[v]) { tmp += f(y, 0); ++ci; continue; }
		if (h[y]>h[v]) { tmp += f(y, 1); ++co; continue; }

		ll vI=f(y, 0), vO=f(y, 1);
		omi.pb(vO-vI); ++cc;
		is+=vI;
	}

	sort(all(omi));
	omi.insert(omi.begin(), 0ll);
	for(int i=1; i<=cc; ++i) omi[i]+=omi[i-1];

	ret = 1ll<<60;
	for(int xi=0; xi<=cc; ++xi) {
		int ri=ci+xi, ro=co+(cc-xi);
		ret = min(ret,
			tmp+max(ri, ro)*1ll*a[v]+
			is+omi[cc-xi]);
	}

	return ret;
}

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> a[i];
	rrep(i, n) cin >> h[i];

	rrep(i, n-1) { int a, b; cin >> a >> b; e[a].pb(b); e[b].pb(a); }

	dfs(1);

	cout << f(1, 2) << '\n';

	return 0;
}
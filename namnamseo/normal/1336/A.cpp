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

int n, k;

vector<int> e[maxn];

int par[maxn];
int dep[maxn];
int cc[maxn];
int dc[maxn];

priority_queue<pp> q;
void dfs(int x) {
	for(int y:e[x]) if (par[x] != y) {
		par[y] = x;
		dep[y] = dep[x]+1;
		dfs(y);
		++cc[x];
	}
	if (!cc[x]) {
		q.emplace(dep[x], x);
	}
}

int main()
{
	cppio(); cin >> n >> k;
	for(int i=1; i<n; ++i) {
		int a, b; cin >> a >> b;
		e[a].pb(b); e[b].pb(a);
	}

	dfs(1);

	ll ans = 0;
	for(;k--;) {
		int gain, v; tie(gain, v) = q.top(); q.pop();
		if (gain != dep[v]-dc[v]) continue;
		ans += gain;
		int p = par[v]; if (p) {
			--cc[p];
			dc[p]+=dc[v]+1;
			if (!cc[p]) {
				q.emplace(dep[p]-dc[p], p);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
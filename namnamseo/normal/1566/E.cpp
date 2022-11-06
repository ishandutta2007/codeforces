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
vector<int> e[maxn];

int buds;
int lc[maxn];
int bleaf;

int dfs(int x, int p) {
	bool leaf = 1;
	lc[x] = 0;
	for (int y:e[x]) if (y != p) {
		int v = dfs(y, x);
		if (v == 1) {
			continue;
		}
		++lc[x];
		leaf = 0;
	}
	if (leaf) return 0;
	++buds;
	bleaf += lc[x];
	return 1;
}

void Work() {
	cin >> n;
	rrep(i, n) e[i].clear();
	rrep(i, n-1) {
		int a, b; cin >> a >> b;
		e[a].pb(b);
		e[b].pb(a);
	}

	buds = 0; bleaf = 0;
	int rv = dfs(1, -1);
	buds -= rv; bleaf -= lc[1];

	int ans = max(lc[1], 1);
	ans += bleaf - buds;

	cout << ans << '\n';
}

int main()
{
	cppio();

	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}

	return 0;
}
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

int n, m, k;
int a[maxn];

vector<pp> e[maxn];

bitset<10> rnk[maxn][10];

int key[maxn];
int gain[10][10];

int ans, ax, cx;

void dfs(int lev)
{
	if (lev == k) {
		if (ax == cx) ++ans;
		return;
	}
	for(int i=lev+1; i; --i) {
		cx ^= gain[lev+1][i];
		dfs(lev+1);
		cx ^= gain[lev+1][i];
	}
}

int main()
{
	cppio();
	cin >> n >> m >> k;
	rrep(i, m) {
		int a, b, c; cin >> a >> b >> c;
		e[a].eb(c, b);
	}
	rrep(i, n) sort(all(e[i]));

	rrep(i, n) {
		int r = 0, s = sz(e[i]);
		for(auto &tmp:e[i]) {
			int j = tmp.y;
			rnk[j][s][++r] = 1;
		}
	}

	rrep(i, n) {
		key[i] = (rand()<<15) | (rand());
		ax ^= key[i];
	}

	rrep(i, n) {
		rrep(j, k) rrep(l, j) if (rnk[i][j][l]) gain[j][l] ^= key[i];
	}

	dfs(0);

	cout << ans << endl;

	return 0;
}
//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define deg(i) sz(adj[i])

const int maxn = 2e5 + 10;
int ans[maxn],
	frm[maxn],
	too[maxn],
	n, k;
vector<int> adj[maxn];

bool check(int x) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (deg(i) > x);
	return cnt <= k;
}

void print(int mxcol, int u = 0, int col = -1, int p = -1) {
	int chcol = deg(u) > mxcol;
	for (auto e : adj[u]) {
		int v = frm[e] ^ too[e] ^ u;
		if (v == p) continue;
		if (deg(u) <= mxcol) {
			chcol++;
			if (chcol == col)
				chcol++;
		}
		ans[e] = chcol;
		print(mxcol, v, chcol, u);
	}
	if (u == 0) {
		for (int i = 1; i < n; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(i);
		adj[se].PB(i);
		frm[i] = fi;
		too[i] = se;
	}
	
	int lo = 0,
		hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	print(hi);

	return 0;
}
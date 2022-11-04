#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 2e5;

vector<int> g[MAXN + 1];
int lvl[MAXN + 1], sz[MAXN + 1];

void dfs(int nod, int par) {
	sz[nod] = 1;
	lvl[nod] = lvl[par] + 1;
	for(auto it : g[nod]) {
		if(it != par) {
			dfs(it, nod);
			sz[nod] += sz[it];
		}
	}
}

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n >> k;
   	for(i = 1; i < n; i++) {
   		int x, y; cin >> x >> y;
   		g[x].push_back(y);
   		g[y].push_back(x);
   	}

   	dfs(1, 0);

   	vector<int> ord(n);
   	iota(ord.begin(), ord.end(), 1);
   	sort(ord.begin(), ord.end(), [&](const int &x, const int &y) {
   			return lvl[x] - sz[x] > lvl[y] - sz[y];
   	});

   	ll ans = 0;
   	for(i = 0; i < k; i++) {
   		ans += lvl[ord[i]] - sz[ord[i]];
   	}
   	cout << ans;

    return 0;
}
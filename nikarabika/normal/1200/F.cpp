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

#define Mod 2520

const int maxn = 1000 + 10,
	  maxv = maxn * Mod;
int next[maxv],
	ans[maxv],
	a[maxn],
	n;
vector<int> gadj[maxn],
	vec;
set<int> s;
char mark[maxv];

inline void relax(int &x) {
	x = (x % Mod + Mod) % Mod;
}

inline int vertex(int u, int x) {
	return u * Mod + x;
}

void dfs(int cur) {
	vec.PB(cur);
	mark[cur] = 1;
	int u = cur / Mod;
	int num = cur % Mod;

	int newnum = cur + a[u];
	relax(newnum);
	int v = gadj[u][newnum % sz(gadj[u])];
	int nxt = vertex(v, newnum);

	if (mark[nxt] == 2) {
		ans[cur] = ans[nxt];
	}
	else if (mark[nxt] == 1) {
		s.clear();
		for (int i = sz(vec) - 1; vec[i] != nxt; i--)
			s.insert(vec[i] / Mod);
		s.insert(nxt / Mod);
		ans[cur] = sz(s);
	}
	else {
		dfs(nxt);
		ans[cur] = ans[nxt];
	}
	mark[cur] = 2;
	vec.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i] = ((a[i] % Mod + Mod) % Mod);
	for (int i = 0; i < n; i++) {
		int fi;
		cin >> fi;
		while (fi--) {
			int se;
			cin >> se, se--;
			gadj[i].PB(se);
		}
	}
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < Mod; j++) {
//			int u = i * Mod + j;
//			if (!mark[u])
//				dfs(u);
//		}
	int q;
	cin >> q;
	while (q--) {
		int fi, se;
		cin >> fi >> se;
		fi--;
		relax(se);
		int u = vertex(fi, se);
		if (!mark[u])
			dfs(u);
		cout << ans[u] << '\n';
	}
	return 0;
}
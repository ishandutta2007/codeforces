#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 4e5 + 7;
int n, m, s;
vi e[N];
int tag[N];
int curp, fa[N], ok;
void dfs(int x, int f) {
	if(x == s) return ;
	if(tag[x]) {
		if(tag[x] == curp) return ;
		cout << "Possible\n";
		vi R = {x};
		for(int u = f; u; u = fa[u]) R.emplace_back(u);
		reverse(R.begin(), R.end());
		cout << sz(R) << '\n';
		for(auto u : R) cout << u << ' ';
		cout << '\n';
		
		R.clear();
		for(int u = x; u; u = fa[u]) R.emplace_back(u);
		reverse(R.begin(), R.end()); 
		cout << sz(R) << '\n';
		for(auto u : R) cout << u << ' ';
		cout << endl;
		
		exit(0);
		return ;
	}
	fa[x] = f, tag[x] = curp;
	for(const int &v : e[x]) dfs(v, x);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
	}
	tag[s] = -1;
	for(const int &v : e[s]) {
		curp = v, dfs(v, s);
	}
	cout << "Impossible\n";
	return 0;
}
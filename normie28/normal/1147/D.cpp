#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int mod = 998244353;
 
void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}
 
string s;
int m, res;
 
int n;
basic_string<pair<int, int>> e[2005];
int vis[2005];
 
void ae(int x, int y, int r) {
	e[x] += {y, r};
	e[y] += {x, r};
}
 
const int INCONSISTENT = 1;
const int CONSTANT = 2;
 
void dfs(int x, int cl, int& status) {
	if (x == n-1)
		status |= CONSTANT;
 
	if (vis[x] != -1) {
		if (vis[x] != cl)
			status |= INCONSISTENT;
		return;
	}
 
	vis[x] = cl;
	for (auto [y, w] : e[x]) {
		dfs(y, w^cl, status);
	}
}
 
void resi(int l) {
	n = 2*m + 1;
	fill(e, e+n, basic_string<pair<int, int>>());
	fill(vis, vis+n, -1);
	for (int i=0, j=m-1; i<j; i++, j--)
		ae(i, j, 0);
	for (int i=m, j=m+l-1; i<j; i++, j--)
		ae(i, j, 0);
	for (int i=0; i<m; i++)
		if (s[i] != '?')
			ae(i, i+m, s[i] - '0');
	ae(m+l-1, 2*m, 1);
	for (int i=m+l; i<2*m; i++)
		ae(i, 2*m, 0);
 
 
	int res = 1;
 
	for (int i=0; i<n; i++) {
		if (vis[i] == -1) {
			int status = 0;
			dfs(i, 0, status);
 
			if (status & INCONSISTENT)
				res = 0;
			else if (status & CONSTANT)
				res = res;
			else
				ad(res, res);
		}
	}
 
	ad(::res, res);
}
 
int main() {
 
	cin >> s;
	m = s.size();
	reverse(s.begin(), s.end());
	for (int l=1; l<m; l++) {
		resi(l);
	}
	cout << res << endl;
}
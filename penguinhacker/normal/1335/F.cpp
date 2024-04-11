#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
unordered_map<char, ar<int, 2>> d={{'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};

int n, m, a1, a2;
vector<vector<bool>> col, vis1, vis2;
vector<vector<ar<int, 2>>> nxt;
vector<vector<vector<ar<int, 2>>>> rev;
vector<ar<int, 2>> cyc;
vector<bool> a;

ar<int, 2> add(ar<int, 2> a, ar<int, 2> b) {
	return {a[0]+b[0], a[1]+b[1]};
}

void dfs1(ar<int, 2> u) {
	if (vis1[u[0]][u[1]]) {
		cyc.push_back(u);
		return;
	}
	vis1[u[0]][u[1]]=1;
	dfs1(nxt[u[0]][u[1]]);
	if (nxt[u[0]][u[1]]==cyc.back()&&u!=cyc[0])
		cyc.push_back(u);
}

void dfs2(ar<int, 2> u, int dep=0) {
	if (col[u[0]][u[1]]==1) {
		a[dep%cyc.size()]=1;
	}
	vis1[u[0]][u[1]]=vis2[u[0]][u[1]]=1;
	for (auto v : rev[u[0]][u[1]]) {
		if (!vis2[v[0]][v[1]]) {
			dfs2(v, dep+1);
		}
	}
}

void solve() {
	a1=a2=0;
	cin >> n >> m;
	col.assign(n, vector<bool>(m));
	vis1=vis2=vector<vector<bool>>(n, vector<bool>(m, 0));
	nxt.assign(n, vector<ar<int, 2>>(m));
	rev.assign(n, vector<vector<ar<int, 2>>>(m));
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for (int j=0; j<m; ++j)
			col[i][j]=s[j]=='0';
	}
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for (int j=0; j<m; ++j) {
			char c=s[j];
			ar<int, 2> x=add(d[c], {i, j});
			nxt[i][j]=x;
			rev[x[0]][x[1]].push_back({i, j});
		}
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!vis2[i][j]) {
				dfs1({i, j});
				a1+=cyc.size();
				a.assign(cyc.size(), 0);
				dfs2(cyc[0]);
				cyc.clear();
				a2+=count(a.begin(), a.end(), 1);
			}
	cout << a1 << ' ' << a2 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
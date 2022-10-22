#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct dsu {
	int par[200000], rank[200000];
	dsu() {iota(begin(par), end(par), 0); }
	int find(int u) {return u==par[u]?u:par[u]=find(par[u]);}
	void join(int u, int v) {
		u=find(u), v=find(v);
		if (u==v) return;
		if (rank[u]<rank[v])
			swap(u, v);
		if (rank[u]==rank[v]) ++rank[u];
		par[v]=u;
	}
} d;

int n;
vector<int> let[26];
string s[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		for (char c : s[i])
			let[c-'a'].push_back(i);
	}
	for (int i=0; i<26; ++i) {
		int x=let[i].size();
		for (int j=1; j<x; ++j)
			d.join(let[i][j-1], let[i][j]);
	}
	int ans=0;
	for (int i=0; i<n; ++i)
		if (i==d.find(i))
			++ans;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
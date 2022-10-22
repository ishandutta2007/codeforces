#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, k, pos[531441], cnt[mxN];
vector<int> adj[mxN], ans;

int hsh(string s) {
	int r=0;
	for (char c : s)
		r=27*r+(c=='_'?26:c-'a');
	return r;
}

vector<int> gen(string s) {
	vector<int> v;
	for (int i=0; i<(1<<k); ++i) {
		string t=s;
		bool ok=1;
		for (int j=0; j<k; ++j) {
			if (i&(1<<j)) {
				ok&=s[j]!='_';
				t[j]='_';
			}
		}
		if (ok) {
			int x=pos[hsh(t)];
			if (x^-1)
				v.push_back(x);
		}
	}
	return v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	memset(pos, -1, sizeof(pos));
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		pos[hsh(s)]=i;
	}
	for (int i=0; i<m; ++i) {
		string s;
		int x;
		cin >> s >> x, --x;
		vector<int> v=gen(s);
		if (find(v.begin(), v.end(), x)==v.end()) {
			cout << "NO";
			return 0;
		}
		for (int i : v)
			if (x^i)
				++cnt[i], adj[x].push_back(i);
	}
	queue<int> q;
	for (int i=0; i<n; ++i)
		if (!cnt[i])
			q.push(i);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		ans.push_back(u);
		for (int v : adj[u])
			if (--cnt[v]==0)
				q.push(v);
	}
	if (ans.size()!=n) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i)
		cout << ans[i]+1 << " ";
	return 0;
}
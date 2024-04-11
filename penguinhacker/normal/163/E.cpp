#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6+1;

struct AC {
	int n=1, sl[mxN+1], c[mxN+1][26];
	int add(string s) {
		int u=0;
		for (char a : s) {
			if (!c[u][a-'a'])
				c[u][a-'a']=n++;
			u=c[u][a-'a'];
		}
		return u;
	}
	void ac() {
		for (queue<int> q({0}); !q.empty(); q.pop()) {
			int u=q.front();
			for (int i=0; i<26; ++i) {
				int v=c[u][i];
				if (v) {
					sl[v]=u?c[sl[u]][i]:0;
					q.push(v);
				} else {
					c[u][i]=c[sl[u]][i];
				}
			}
		}
	}
	int feed(int u, char a) {
		return c[u][a-'a'];
	}
} ac;

int n, m, t, a[mxN], tin[mxN], tout[mxN], ft[2*mxN+1];
vector<int> adj[mxN];
bool vis[mxN];

void upd(int i, int x) {
	for (++i; i<=2*mxN; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for (++i; i; i-=i&-i)
		r+=ft[i];
	return r;
}

void dfs(int u=0) {
	tin[u]=t++;
	for (int v : adj[u])
		dfs(v);
	tout[u]=t++;
}

void upd2(int i, int x) {
	upd(tin[i], x);
	upd(tout[i], -x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		a[i]=ac.add(s), vis[i]=1;
	}
	ac.ac();
	for (int i=1; i<ac.n; ++i)
		adj[ac.sl[i]].push_back(i);
	dfs();
	for (int i=0; i<n; ++i)
		upd2(a[i], 1);
	while(m--) {
		string s;
		cin >> s;
		if (s[0]=='+') {
			int u=stoi(s.substr(1))-1;
			if (!vis[u])
				vis[u]=1, upd2(a[u], 1);
		} else if (s[0]=='-') {
			int u=stoi(s.substr(1))-1;
			if (vis[u])
				vis[u]=0, upd2(a[u], -1);
		} else {
			ll ans=0;
			int u=0;
			for (int i=1; i<s.size(); ++i) {
				u=ac.feed(u, s[i]);
				ans+=qry(tin[u]);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
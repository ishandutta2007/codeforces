#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, p[mxN], xum;
set<int> bad[mxN];
vector<ar<int, 3>> e;
bool used[1000][1000];

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

void case1() {
	iota(p, p+n, 0);
	for (int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		used[u][v]=used[v][u]=1;
		e.push_back({w, u, v});
		xum^=w;
	}
	bool ux=0;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (!used[i][j]) {
				int u=find(i), v=find(j);
				if (u^v)
					p[v]=u;
				else
					ux=1;
			}
	ll ans=ux?0:xum;
	sort(e.begin(), e.end());
	for (ar<int, 3> x : e) {
		int u=find(x[1]), v=find(x[2]);
		if (u^v) {
			p[v]=u;
			ans+=x[0];
		}
	}
	if (ux) {
		cout << ans;
		return;
	}
	// look for more
	vector<ar<int, 2>> free;
	vector<ar<int, 3>> useful;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (!used[i][j])
				free.push_back({i, j});
	iota(p, p+n, 0);
	for (ar<int, 3> x : e) {
		int u=find(x[1]), v=find(x[2]);
		if (u^v) {
			p[v]=u;
			useful.push_back(x);
		}
	}
	// iterate over all free edges to not take
	for (int i=0; i<free.size(); ++i) {
		iota(p, p+n, 0);
		ll cur=0;
		for (int j=0; j<free.size(); ++j)
			if (i^j) {
				int u=find(free[j][0]), v=find(free[j][1]);
				if (u^v)
					p[v]=u;
			}
		for (ar<int, 3> x : e) {
			int u=find(x[1]), v=find(x[2]);
			if (u^v) {
				p[v]=u;
				cur+=x[0];
			}
		}
		ans=min(ans, cur);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if (n<=1000) {
		case1();
		return 0;
	}
	for (int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		bad[u].insert(v);
		bad[v].insert(u);
		e.push_back({w, u, v});
	}
	set<int> s;
	for (int i=0; i<n; ++i) {
		p[i]=i;
		s.insert(i);
	}
	while(s.size()) {
		int src=*s.begin();
		s.erase(s.begin());
		for (queue<int> q({src}); q.size(); q.pop()) {
			int u=q.front();
			for (auto it=s.begin(); it!=s.end();) {
				if (bad[u].find(*it)==bad[u].end()) {
					q.push(*it);
					p[*it]=src;
					it=s.erase(it);
				} else
					++it;
			}
		}
	}
	ll ans=0;
	sort(e.begin(), e.end());
	for (ar<int, 3> x : e) {
		int u=find(x[1]), v=find(x[2]);
		if (u^v) {
			p[v]=u;
			ans+=x[0];
		}
	}
	cout << ans;
	return 0;
}
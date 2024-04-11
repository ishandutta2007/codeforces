#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, c1, c2;
set<pair<int, char>> adj[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(m--) {
		char t;
		cin >> t;
		if (t=='+') {
			int u, v;
			char c;
			cin >> u >> v >> c, --u, --v;
			auto it=adj[v].lower_bound({u, 'a'});
			if (it!=adj[v].end()&&it->first==u) {
				++c1;
				c2+=it->second==c;
			}
			adj[u].emplace(v, c);
		} else if (t=='-') {
			int u, v;
			cin >> u >> v, --u, --v;
			auto it=adj[u].lower_bound({v, 'a'});
			assert(it!=adj[u].end()&&it->first==v);
			char c=it->second;
			adj[u].erase(it);
			it=adj[v].lower_bound({u, 'a'});
			if (it!=adj[v].end()&&it->first==u) {
				--c1;
				c2-=it->second==c;
			}
		} else {
			int k;
			cin >> k;
			cout << (c2||(c1&&k%2)?"YES":"NO") << "\n";
		}
	}
	return 0;
}
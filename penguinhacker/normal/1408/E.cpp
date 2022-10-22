#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5; //change
struct DSU {
	int rank[mxN], p[mxN];
	DSU() {
		memset(rank, 0, sizeof(rank));
		iota(p, p+mxN, 0);
	}
	int find(int x) {return x==p[x]?x:p[x]=find(p[x]);}
	bool merge(int a, int b) {
		a=find(a), b=find(b);
		if (a==b) return 0;
		if (rank[a]<rank[b]) swap(a, b);
		if (rank[a]==rank[b]) ++rank[a];
		p[b]=a;
		return 1;
	}
} dsu;

int n, m;
int a[mxN], b[mxN];
vector<ar<int, 3>> nodes; //weight, #, which set
vector<int> s[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x, --x;
			ans += a[i] + b[x];
			nodes.push_back({a[i] + b[x], x, i});
		}
	}
	sort(nodes.begin(), nodes.end());
	for (int i = nodes.size() - 1; i >= 0; --i) {
		ar<int, 3> cur = nodes[i];
		int w = cur[0], ind = cur[1], group = cur[2];
		if (s[group].empty()) {
			s[group].push_back(ind);
			ans -= w;
		}
		else {
			if (dsu.merge(ind, s[group][0])) {
				s[group].push_back(ind);
				ans -= w;
			}
		}
	}
	cout << ans;
	return 0;
}
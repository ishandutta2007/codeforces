#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
vector<int> v[202020];
vector<int> h;

int c[202020];

void dfs(int s, int e, int d) {
	c[s] = 1;
	for (auto u : v[s]) {
		if (u == e) continue;
		dfs(u,s,d+1);
		c[s] += c[u];
	}
	h.push_back(d-(c[s]-1));
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0,0);
	sort(h.rbegin(),h.rend());
	ll u = 0;
	for (int i = 0; i < k; i++) u += h[i];
	cout << u << "\n";
}
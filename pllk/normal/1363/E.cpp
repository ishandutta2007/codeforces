#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int a[202020];
int b[202020];
int c[202020];
vector<int> v[202020];
ll r;

pair<int,int> dfs(int s, int e, int z) {
	z = min(z,a[s]);
	int c1 = 0, c2 = 0;
	if (b[s] == 0 && c[s] == 1) c1++;
	if (b[s] == 1 && c[s] == 0) c2++;
	for (auto u : v[s]) {
		if (u == e) continue;
		auto d = dfs(u,s,z);
		c1 += d.first;
		c2 += d.second;
	}
	while (c1 && c2) {
		r += 2*z;
		c1--; c2--;
	}
	return {c1,c2};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n-1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	auto d = dfs(1,0,a[1]);
	if (d.first == 0 && d.second == 0) {
		cout << r << "\n";
	} else {
		cout << "-1\n";
	}
}
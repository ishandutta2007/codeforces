#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[101010];
int d[101010];

int r0, r1;

void dfs(int s, int e, int c) {
	if (s != 1 && v[s].size() == 1) {
		if (c%2 == 0) r0 = 1;
		else r1 = 1;
		return;
	}
	for (auto x : v[s]) {
		if (x == e) continue;
		dfs(x,s,c+1);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		d[a]++; d[b]++;
	}
	int c1 = n-1;
	for (int i = 1; i <= n; i++) {
		int c = 0;
		for (auto x : v[i]) {
			if (d[x] == 1) c++;
		}
		if (c > 1) c1 -= c-1;
	}
	dfs(1,0,0);
	int c2 = 1;
	if (r0 && r1) c2 = 3;
	if (v[1].size() == 1 && r1) c2 = 3;
	cout << c2 << " " << c1 << "\n";
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int w[101010];
int r[101010];
int a[202020], b[202020];
int z[202020];
vector<int> v[101010];
vector<int> f;

void check(int k) {
	if (z[k]) return;
	if (r[a[k]] <= w[a[k]] || r[b[k]] <= w[b[k]]) {
		z[k] = 1;
		f.push_back(k);
		r[a[k]]--; r[b[k]]--;
		for (auto x : v[a[k]]) check(x);
		for (auto x : v[b[k]]) check(x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		r[a[i]]++; r[b[i]]++;
		v[a[i]].push_back(i);
		v[b[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		check(i);
	}
	if (f.size() == m) {
		reverse(f.begin(),f.end());
		cout << "ALIVE\n";
		for (auto x : f) cout << x << " ";
		cout << "\n";
	} else {
		cout << "DEAD\n";
	}
}
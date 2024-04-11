#include <iostream>
#include <vector>

using namespace std;

int n, k;
int m[202020];
int d[202020];
int c[202020];
vector<int> v[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		d[m[i]]++;
	}
	for (int i = 1; i <= k; i++) cin >> c[i];
	int s = 0;
	int r = 0;
	for (int i = k; i >= 1; i--) {
		s += d[i];
		int u = s/c[i];
		if (s%c[i] != 0) u++;
		r = max(r,u);
	}
	cout << r << "\n";
	int w = 0;
	for (int i = k; i >= 1; i--) {
		for (int j = 1; j <= d[i]; j++) {
			v[w].push_back(i);
			w = (w+1)%r;
		}
	}
	for (int i = 0; i < r; i++) {
		cout << v[i].size() << " ";
		for (auto x : v[i]) cout << x << " ";
		cout << "\n";
	}
}
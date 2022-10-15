#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v[505050];
int x[505050];
int y[505050];
int r[505050];
int h = 0;

void lol(int s) {
	h++;
	for (auto u : v[s]) r[y[u]] = h;
	for (int i = 1; ; i++) {
		if (r[i] != h) {
			y[s] = i;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<pair<int,int>> u;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		u.push_back({x[i],i});
	}
	sort(u.begin(),u.end());
	for (int i = 0; i < u.size(); i++) lol(u[i].second);
	for (int i = 1; i <= n; i++) {
		if (x[i] != y[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << u[i].second << " ";
	}
	cout << "\n";
}
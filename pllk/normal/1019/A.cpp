#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;
int p[3333];
int c[3333];
vector<int> v[3333];
ll pp = 999999999999999LL;

void lol(int u) {
	vector<int> z;
	ll cc = 0;
	int k = v[1].size();
	for (int i = 2; i <= m; i++) {
		int h = v[i].size();
		for (int j = 0; j < v[i].size(); j++) {
			if (h >= u) {
				cc += v[i][j];
				k++;
				h--;
			} else {
				z.push_back(v[i][j]);
			}
		}
	}
	sort(z.begin(),z.end());
	int i = 0;
	while (k < u) {
		if (i == z.size()) return;
		cc += z[i];
		k++;
		i++;
	}
	pp = min(pp,cc);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
		v[p[i]].push_back(c[i]);
	}
	for (int i = 1; i <= m; i++) sort(v[i].begin(),v[i].end());
	if (n == 1) {
		if (p[1] == 1) cout << 0 << "\n";
		else cout << c[1] << "\n";
		return 0;
	}
	for (int u = 2; u <= n; u++) {
		lol(u);
	}
	cout << pp << "\n";
}
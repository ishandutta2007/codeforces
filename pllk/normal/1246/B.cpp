#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int n, k;
ll r;
map<vector<pair<int,int>>,int> z;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vector<pair<int,int>> a, b;
		for (int u = 2; u*u <= x; u++) {
			int c = 0;
			while (x%u == 0) {
				x /= u;
				c++;
			}
			c %= k;
			if (c%k == 0) continue;
			a.push_back({u,c});
			b.push_back({u,k-c});
		}
		if (x != 1) {
			a.push_back({x,1});
			b.push_back({x,k-1});
		}
		r += z[b];
		z[a]++;
	}
	cout << r << "\n";
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
using namespace std;
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;
const int root = 540;
vector <int> num[root], dist[root];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	vector <int> arr(n);
	for (int i = 0; i < n; i += root) {
		for (int j = i; j < i + root and j < n; ++j) {
			cin >> arr[j];
			num[i / root].push_back(0);
			dist[i / root].push_back(0);
		}
	}
	dist[0][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		int j = i / root, k = i % root;
		if (i + arr[i] >= n) {
			num[j][k] = 0;
			dist[j][k] = i;
		}
		else {
			int ind = i;
			int cnt = 0;
			while (ind != dist[ind / root][ind % root] and ind < j * root + root) {
				cnt++;
				ind = arr[ind] + ind;
			}
			num[j][k] = cnt;
			dist[j][k] = ind;
		}
	}
	
	while (m--) {
		int c; cin >> c;
		if (c == 0) {
			int i, x; cin >> i >> x;
			--i;
			arr[i] = x;
			int j = i / root, k = i % root;
			if (i + arr[i] >= n) {
				num[j][k] = 0;
				dist[j][k] = i;
			}
			else {
				int cnt = 1;
				int ind = i + arr[i];
				while (ind != dist[ind / root][ind % root] and ind < j * root + root) {
					cnt++;
					ind = arr[ind] + ind;
				}
				num[j][k] = cnt;
				dist[j][k] = ind;
			}
			for (int f = i - 1; f != j * root - 1; --f) {
				int id = arr[f] + f;
				if (id >= n) {
					num[f / root][f % root] = 0;
					dist[f / root][f % root] = f;
				}
				else if (id >= j * root + root) {
					num[f / root][f % root] = 1;
					dist[f / root][f % root] = id;
				}
				else {
					num[f / root][f % root] = num[id / root][id % root] + 1;
					dist[f / root][f % root] = dist[id / root][id % root];
				}
			}
		}
		else {
			int i; cin >> i;
			i--;
			int nm = 0, ind = i;
			while (ind != dist[ind / root][ind % root]) {
				nm += num[ind / root][ind % root];
				ind = dist[ind / root][ind % root];
			}
			cout << ind + 1 << ' ' << nm + 1 << '\n';
		}
	}
}
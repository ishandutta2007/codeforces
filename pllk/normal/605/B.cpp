#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<pair<int,int>,int>> v;
vector<pair<int,int>> u;
pair<int,int> t[101010];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(make_pair(a,1-b),i));
	}
	sort(v.begin(), v.end());
	int c = 1;
	int k = 0;
	for (int i = 0; i < m; i++) {
		if (v[i].first.second == 1) {
			if (k == u.size()) {
				cout << "-1\n";
				return 0;
			} else {
				t[v[i].second] = u[k];
				if (u[k].first+2 >= u[k].second) k++;
				else u[k].first++;
			}
		} else {
			t[v[i].second] = {c,c+1};
			if (c+1 != 2) u.push_back({1,c+1});
			c++;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << t[i].first << " " << t[i].second << "\n";
	}
}
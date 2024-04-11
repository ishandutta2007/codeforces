#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int aa[1111], bb[1111], cc[1111], dd[1111];

void lol(vector<int> v) {
	if (v.size() == 1) return;
	vector<pair<int,int>> e;
	for (auto x : v) {
		e.push_back({aa[x],1});
		e.push_back({cc[x],-1});
	}
	sort(e.begin(),e.end());
	int c = 0;
	for (auto x : e) {
		c += x.second;
		if (c == 0) {
			vector<int> v1, v2;
			for (auto u : v) {
				if (cc[u] <= x.first) v1.push_back(u);
				else v2.push_back(u);
			}
			if (v1.size() == 0 || v2.size() == 0) break;
			lol(v1);
			lol(v2);
			return;
		}
	}
	e.clear();
	for (auto x : v) {
		e.push_back({bb[x],1});
		e.push_back({dd[x],-1});
	}
	sort(e.begin(),e.end());
	c = 0;
	for (auto x : e) {
		c += x.second;
		if (c == 0) {
			vector<int> v1, v2;
			for (auto u : v) {
				if (dd[u] <= x.first) v1.push_back(u);
				else v2.push_back(u);
			}
			if (v1.size() == 0 || v2.size() == 0) break;
			lol(v1);
			lol(v2);
			return;
		}
	}
	cout << "NO\n";
	exit(0);
}

int main() {
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		cin >> aa[i] >> bb[i] >> cc[i] >> dd[i];
		v.push_back(i);
	}
	lol(v);
	cout << "YES\n";
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void lol1(vector<pair<int,int>> v, int k) {
	vector<pair<int,int>> u;
	for (int i = 0; i < n; i++) {
		if (i != k) u.push_back(v[i]);
	}
	int d = u[1].first-u[0].first;
	for (int i = 1; i < n-1; i++) {
		if (u[i].first-u[i-1].first != d) return;
	}
	cout << v[k].second << "\n";
	exit(0);
}

void lol2(vector<pair<int,int>> v, int d) {
	int x = v[0].first;
	int e = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].first-x == d) {
			x = v[i].first;
		} else {
			if (e) return;
			e = v[i].second;
		}
	}
	if (e == 0) e = 1;
	cout << e << "\n";
	exit(0);
}

int main() {
	cin >> n;
	vector<pair<int,int>> v;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back({x,i});
	}
	sort(v.begin(),v.end());
	lol1(v,0);
	lol1(v,1);
	lol2(v,v[1].first-v[0].first);
	cout << -1 << "\n";
}
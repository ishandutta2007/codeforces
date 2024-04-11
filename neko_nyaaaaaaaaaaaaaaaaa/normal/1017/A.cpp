#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int x, y, z, t;
		cin >> x >> y >> z >> t;
		a[i].first = x+y+z+t; a[i].second = i;
		a[i].first *= -1;
	}
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++) {
		if (a[i].second == 0) {cout << i+1;}
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	// cout << fixed << setprecision(12);
	
	vector<int> a(2, 1);
	while (a[a.size() - 1] <= 1000) {
		a.push_back(a[a.size() - 1] + a[a.size() - 2]);
	}
	vector<bool> c(1001, 0);
	for (int i = 1; i < a.size()-1; i++) {
		c[a[i]] = 1;
	}
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (c[i]) {cout << "O";}
		else {cout << "o";}
	}
	
	return 0;
}
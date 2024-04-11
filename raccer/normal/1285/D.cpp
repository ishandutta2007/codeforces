#include <bits/stdc++.h>
using namespace std;

int a[100010];

int solve(int k, vector <int> v) {
	if (!v.size()) return 0;
	vector <int> v1, v2;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i];
		if (a[x] >> k & 1) v1.push_back(x);
		else v2.push_back(x); 
	}
	if (k == 0) return v1.size() && v2.size();
	if (!v1.size()) return solve(k - 1, v2);
	if (!v2.size()) return solve(k - 1, v1);
	int t1 = solve(k - 1, v1), t2 = solve(k - 1, v2);
	return min(t1, t2) + (1 << k);
}

int main () {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
	cout << solve(29, v) << endl;
	return 0;
}
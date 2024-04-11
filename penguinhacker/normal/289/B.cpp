#include <bits/stdc++.h>
using namespace std;

int n, m, d;
vector<int> v, val;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> d;
	for (int i=0, a; i<n*m; ++i) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int parity = v[0]%d;
	for (int i=1; i<n*m; ++i) {
		if (v[i]%d!=parity) {
			cout << -1;
			return 0;
		}
	}	
	for (int i:v)
		val.push_back(i/d);

	int curr=0;
	for (int i:val)
		curr+=i-val[0];
	int ans = curr;
	for (int i=1; i<n*m; ++i) {
		curr += (i+(i-n*m))*(val[i]-val[i-1]);
		ans = min(ans, curr);
	}
	cout << ans;
	return 0;
}
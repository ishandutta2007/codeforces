#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double eps = 1e-10;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {cout << -1; return 0;}
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 1) {cout << -1; return 0;}
	}
	b.push_back(b[0]);
	
	double ans = m;
	for (int i = n; i; i--) {
		double f = ans/(b[i] - 1);
		ans += f;
		
		f = ans/(a[i-1] - 1);
		ans += f;
	}
	cout << fixed << setprecision(12) << ans-m;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cout << fixed << setprecision(12);
	int n;
	double r;
	cin >> n >> r;
	vector<double> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<double> pos(n, 0);
	for (int i = 0; i < n; i++) {
		double ans = r;
		for (int j = 0; j < i; j++) {
			if (abs(x[i] - x[j]) > r*2) {continue;}
			ans = max(ans, sqrt((r*2)*(r*2) - abs(x[i] - x[j])*abs(x[i] - x[j])) + pos[j]);
		}
		pos[i] = ans;
		cout << pos[i] << " ";
	}
	
	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
vector<pair<int, double>> ans[52];
 
int main() {
	int n, w, m;
	cin >> n >> w >> m;
	double s = (n * w) / (m * 1.0), c = w, b = 1, k = 0;
	for (int i = 0; i < m; i++) {
		double ne = s;
		while (1) {
			if (ne + 10e-7 > c) {
				ans[i].push_back(make_pair(b, c));
				ne -= c;
				c = w;
				b++;
				if (++k > 2) {
					cout << "NO";
					return 0;
				}
				k = 0;
				if (abs(ne) < 10e-7)
					break;
			} else {
				ans[i].push_back(make_pair(b, ne));
				c -= ne;
				k++;
				break;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		for (auto it : ans[i])
			cout << fixed << setprecision(0) << it.first << " "
					<< setprecision(6) << it.second << " ";
		cout << "\n";
	}
}
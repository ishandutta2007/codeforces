#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<bool>> e(1000, vector<bool>(1000, 0));

int main() {
	ios::sync_with_stdio(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	if (a != 1 && b != 1) {cout << "NO"; return 0;}
	
	if (n == 1) {cout << "YES\n0"; return 0;}
	
	if (n == 2) {
		if (a == 1 && b == 2) {
			cout << "YES\n01\n10";
		} else if (a == 2 && b == 1) {
			cout << "YES\n00\n00";
		} else {cout << "NO";}
		return 0;
	}
	
	if (n == 3 && a == 1 && b == 1) {
		cout << "NO";
		return 0;
	}
	
	cout << "YES\n";
	
	int k = n - max(a, b);
	for (int i = 1; k--; i++) {
		int j = i-1;
		e[i][j] = e[j][i] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {cout << 0;}
			else {
				if (b == 1) {
					cout << e[i][j];	
				} else {
					cout << !e[i][j];
				}
			}
		}
		cout << '\n';
	}
	
	return 0;
}
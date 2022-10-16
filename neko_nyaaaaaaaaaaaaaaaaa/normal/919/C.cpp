#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	if (n == 1 && m == 1 && k == 1) {
		char c;
		cin >> c;
		if (c == '*') {cout << 0; return 0;}
		else {cout << 1; return 0;}
	}
	
	if (n == 1 || m == 1) {
		ll ans = 0;
		vector<char> c(max(n, m));
		for (int i = 0; i < max(n, m); i++) {
			cin >> c[i];
		}
		int count = 0;
		for (int i = 0; i < c.size(); i++) {
			if (c[i] == '*') {count = 0;}
			else {
				count++;
				if (count >= k) {ans++;}
			}
		}
		cout << ans; return 0;
	}
	
	vector<vector<char>> c(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	ll ans = 0;
	
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '*') {count = 0; continue;}
			else {
				count++;
				if (count >= k) {ans++;} 
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (c[j][i] == '*') {count = 0; continue;}
			else {
				count++;
				if (count >= k) {ans++;} 
			}
		}
	}
	
	if (k == 1) {cout << ans/2; return 0;}
	
	cout << ans;
	
	return 0;
}
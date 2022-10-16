#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(int n, int k) {
	vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	if (a == vector<int>({1, 2, 1, 2})) {cout << -1; return 0;}
	if (a == vector<int>({2, 1, 2, 1})) {cout << -1; return 0;}
	if (a == vector<int>({1, 1, 2, 2})) {cout << "2\n1 1 1\n2 4 1"; return 0;}
	if (a == vector<int>({2, 2, 1, 1})) {cout << "2\n2 1 1\n1 4 1"; return 0;}
	if (a == vector<int>({0, 0, 1, 1})) {cout << "1\n1 4 1"; return 0;}
	if (a == vector<int>({1, 1, 0, 0})) {cout << "1\n1 1 1"; return 0;}
	if (a == vector<int>({1, 0, 1, 0})) {cout << "2\n1 2 1\n1 1 1"; return 0;}
	if (a == vector<int>({0, 1, 0, 1})) {cout << "2\n1 3 1\n1 4 1"; return 0;}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	if (n == 1) {solve(n, k); return 0;}
	
	vector<vector<int>> a(4, vector<int>(n));
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	vector<vector<int>> ans;
	for (int kk = 1; kk <= 20000; kk++) {
		vector<int> move(3);
		bool flag = 0;
		
		for (int i = 0; i < n; i++) {
			if (a[1][i] == a[0][i] && a[1][i]) {
				move[0] = a[1][i];
				move[1] = 1;
				move[2] = i+1;
				ans.push_back(move);
				a[1][i] = a[0][i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[2][i] == a[3][i] && a[2][i]) {
				move[0] = a[2][i];
				move[1] = 4;
				move[2] = i+1;
				ans.push_back(move);
				a[2][i] = a[3][i] = 0;
			}
		}
		
		// rotating cars
		int r = -1, c = -1;
		for (int i = 1; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) {r = i; c = j; break;}
			}
			if (r != -1 || c != -1) break;
		}
		
		if (r == -1) {cout << -1; return 0;}
		
		for (int kkk = 1; kkk < 2*n; kkk++) {
			if (r == 1) {
				if (c == 0) {
					swap(a[1][0], a[2][0]);
					if (a[1][0]) {
						ans.push_back({a[1][0], 2, 1});
					}
					r = 2;
				} else {
					swap(a[1][c], a[1][c-1]);
					if (a[r][c]) {
						ans.push_back({a[r][c], r+1, c+1});
					}
					c--;
				}
			} else {
				if (c == n-1) {
					swap(a[1][n-1], a[2][n-1]);
					if (a[r][c]) {
						ans.push_back({a[r][c], r+1, c+1});
					}
					r = 1;
				} else {
					swap(a[2][c], a[2][c+1]);
					if (a[r][c]) {
						ans.push_back({a[r][c], r+1, c+1});
					}
					c++;
				}
			}
		}
	}
	
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < 3; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	vector<vector<string>> cell(9, vector<string>(3));

	for (ll i = 0; i < 3; i++) {
		for (ll j = 0; j < 3; j++) {
			cin >> cell[j][i];
		}
	}
	for (ll i = 0; i < 3; i++) {
		for (ll j = 3; j < 6; j++) {
			cin >> cell[j][i];
		}
	}
	for (ll i = 0; i < 3; i++) {
		for (ll j = 6; j < 9; j++) {
			cin >> cell[j][i];
		}
	}
	int x, y;
	cin >> x >> y;
	x--;
	x %= 3;
	y %= 3;
	if (y == 0) {y = 3;}
	int cellans = x*3 + y - 1;
	bool flag = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cell[cellans][i][j] == '.') {flag = 1; cell[cellans][i][j] = '!';} 
		}
	}
	if (!flag) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (cell[i][j][k] == '.') {cell[i][j][k] = '!';}
				}
			}
		}
	}
	for (ll i = 0; i < 3; i++) {
		for (ll j = 0; j < 3; j++) {
			cout <<  cell[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (ll i = 0; i < 3; i++) {
		for (ll j = 3; j < 6; j++) {
			cout <<  cell[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (ll i = 0; i < 3; i++) {
		for (ll j = 6; j < 9; j++) {
			cout <<  cell[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
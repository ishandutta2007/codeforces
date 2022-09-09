
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int a[304][304];
int b[304];


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	//
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			if (a[i][j] != i) {
				bool ok = true;
				for (int k = 1; j <= n; k++) {
					if (b[k] < a[i][j] && b[k] != i) ok = false;
					if (b[k] == a[i][j]) break;
				}
				if (ok) {
					cout << a[i][j] << " ";
					break;
				}
			}
	//
	return 0;
};
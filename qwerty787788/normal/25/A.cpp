#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
//
int n;
int a[101];

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = a[i]%2;
	}
	if (a[0] != a[1]) {
		if (a[2] == a[0]) cout << 2 << endl; else
						  cout << 1 << endl;
	} else {
		for (int i = 2; i < n; i++)
			if (a[i] != a[0]) {
				cout << i+1 << endl;
				return 0;
			}
	}
	//
	return 0;
}
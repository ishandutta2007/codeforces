#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> g(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (g[i] == 0) {min++;}
	}
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (j <= i && g[j] == 1) {count++;}
			if (j > i && g[j] == 0) {count++;}
		}
		if (count < min) {min = count;}
	}
	int ans = n-min;
	cout << ans;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int i = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < x) {count++;}
	}
	ans = x - count;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {ans++;}
	}
	cout << ans;
	
	return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

//
int n, k, last, c;
int a[365];

//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> k >> c;
	for (int i = 0; i < c; i++)
		cin >> a[i];
	//
	last = 0;
	int sum = 0;
	for (int i = 0; i < c; i++) {
		while (a[i]-last > k) {
			last += k;
			sum++;
		}
		last = a[i];
		sum++;
	}
	while (n - last >= k) {
		sum++;
		last += k;
	}
	cout << sum << endl;
	//
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
long long n, x;
int a[101];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x] = i + 1;
	}
	//
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	//
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, k;
int a[1000];
int sum = 0;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	for (int i = 0; i < n; i++) {
		if (a[i] >= k) a[i]-= k; 
		if (a[i] >= k) a[i]-= k;
		if (a[i] >= k) a[i]-= k;
		sum += a[i];
	}
	cout << sum << endl;
	//
	return 0;
}
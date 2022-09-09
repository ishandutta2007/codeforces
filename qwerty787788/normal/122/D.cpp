#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
//
int n, k;
int a[100001];
//
int min1 =1;
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		a[i] = int(c-'0');
	}
	//
	min1 = 1;
	while ((min1 < n) && (k > 0)) {
		if ((a[min1] == 4) && (a[min1+1] == 7)) {
			k--;
			if (min1 % 2 == 0) {
				a[min1] = 7;
				min1 -= 2;
			} else {
				a[min1+1] = 4;
			}
		}
		min1++;
		if ((min1 + 2 <= n) && (min1 % 2 == 1)){
			if ((a[min1] == 4) && (a[min1+2] == 7)) {
				if ((a[min1+1] == 4) || (a[min1+1] == 7)) k %= 2;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i+1];
	cout << endl;
	//
	return 0;
}
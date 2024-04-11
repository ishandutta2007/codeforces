#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, sum;
int a[1000];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int max_elem = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[max_elem]) max_elem = i;
	}
	for (int i = max_elem-1; i >= 0; i--) {
		sum++;
		swap(a[i], a[i+1]);
	}
	int min_elem = n-1;
	for (int i = n-1; i >= 0; i--)
		if (a[i] < a[min_elem]) min_elem = i;
	for (int i = min_elem; i < n-1; i++) {
		sum++;
		swap(a[i], a[i+1]);
	}
	cout << sum << endl;
	//
}
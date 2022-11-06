#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
	}
	printf("%.12f", sum / n);
}
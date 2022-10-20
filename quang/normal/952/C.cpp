#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
int a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (abs(a[i] - a[i + 1]) >= 2) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;
	if (n % 2 == 1) cout << n / 2 << endl;
	else cout << (n - (1 << (int)log2(n))) / 2 << endl;
	return 0;
}
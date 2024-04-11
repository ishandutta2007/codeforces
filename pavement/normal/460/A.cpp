#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, i;
	cin >> n >> m;
	for (i = 1; n > 0; i++) {
		if (i % m == 0) n++;
		n--;
	}
	cout << i - 1;
}
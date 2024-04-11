#include <bits/stdc++.h>
using namespace std;

int digsum(int x) {
 return x == 0 ? 0 : x % 10 + digsum(x / 10);
}

int k, c = 0;

int main() {
	cin >> k;
	for (int i = 0;; i++)
		if (digsum(i) == 10 && ++c == k) return cout << i, 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, lo, hi, a = 0,  i;
	cin >> n;
	cin >> lo;
	hi = lo;
	n--;
	while (n--) {
		cin >> i;
		if (i > hi) {
			hi = i;
			a++;
		} else if (i < lo) {
			lo = i;
			a++;
		}
	}
	cout << a;
}
#include <bits/stdc++.h>
using namespace std;

void printBits(int n) {
	for (int i = 9; i >= 0; i--)
		cout << !!(n & (1<<i));
	cout << '\n';
}

char bit[15];

/*
0 - idk value
1 - toggle value
2 - set
3 - unset
*/

int main() {
	int n, v;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> v;
		if (c == '|') {
			for (int i = 0; i < 10; i++)
				if (v & (1<<i)) bit[i] = 2;
		} else if (c == '^') {
			for (int i = 0; i < 10; i++) {
				if (!(v & (1<<i))) continue;
				if (bit[i] == 0) bit[i] = 1;
				else if (bit[i] == 1) bit[i] = 0;
				else if (bit[i] == 2) bit[i] = 3;
				else bit[i] = 2;
			}
		} else {
			for (int i = 0; i < 10; i++) {
				if (!(v & (1<<i))) {
					bit[i] = 3;
					continue;
				}
			}
		}
	}
	int set = 0, unset = 0, tog = 0;
	for (int i = 0; i < 10; i++) {
		if (bit[i] == 1) tog |= (1<<i);
		else if (bit[i] == 2) set |= (1<<i);
		else if (bit[i] == 3) unset |= (1<<i);
	}
	cout << "2\n| " << (set | unset) << "\n^ " << (tog | unset) << '\n';
}
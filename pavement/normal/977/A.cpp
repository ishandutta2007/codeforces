#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	int k, len;
	cin >> n >> k;
	len = n.length();
	while (k--) {
		if (n[len - 1] == '0') len--;
		else n[len - 1] -= 1;
	}
	for (int i = 0; i < len; i++) cout << n[i];
}
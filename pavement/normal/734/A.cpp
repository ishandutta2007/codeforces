#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d = 0, a = 0;
	char c;
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'D') d++;
		else a++;
	}
	if (d == a) cout << "Friendship";
	else if (d > a) cout << "Danik";
	else cout << "Anton";
}
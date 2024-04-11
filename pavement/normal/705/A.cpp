#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	bool h = true;
	cin >> n;
	while (n--) {
		if (h) cout << "I hate ";
		else cout << "I love ";
		if (n == 0) cout << "it";
		else cout << "that ";
		h = !h;
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto is_lucky = [&](int x) -> bool {
	    x = abs(x);
	    for (int n = x; n; n /= 10) {
	        if (n % 10 == 8) return true;
	    }
	    return false;
	};

	int a;
	cin >> a;

	int b;
	for (b = a + 1; !is_lucky(b); b++);

	cout << b - a << '\n';
	return 0;
}
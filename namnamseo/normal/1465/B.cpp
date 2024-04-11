#include <bits/stdc++.h>
using namespace std;

bool ok(long long n) {
	auto t = n;
	while (t) {
		int x = t%10;
		if (x && n%x) return 0;
		t /= 10;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc; cin >> tc;
for(;tc--;) {
	long long n;
	cin >> n;
	while (!ok(n)) ++n;
	cout << n << '\n';
}
	return 0;
}
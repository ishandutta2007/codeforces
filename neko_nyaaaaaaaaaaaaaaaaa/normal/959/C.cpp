#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void solve1() {
	if (n <= 5) {cout << -1 << "\n"; return;}
	if (n == 6) {
		cout << "1 2\n1 3\n1 4\n4 5\n4 6\n";
		return;
	}
	if (n == 7) {
	cout << "1 2\n1 3\n1 4\n4 5\n4 6\n1 7\n";
		return;
	}
	if (n >= 8) {
		cout << "1 2\n1 3\n2 4\n2 5\n3 6\n4 7\n4 8\n";
	}
	for (int i = 9; i <= n; i++) {
		cout << 3 << " " << i << '\n';
	}
	
}

void solve2() {
	for (int i = 2; i <= n; i++) {
		cout << i-1 << " " << i << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	cin >> n;
	solve1();
	solve2();
	
	return 0;
}
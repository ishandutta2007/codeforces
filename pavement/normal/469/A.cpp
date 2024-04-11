#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned int n, p, i;
	set<int> s;
	cin >> n >> p;
	while (p--) {
		cin >> i;
		s.insert(i);
	}
	cin >> p;
	while (p--) {
		cin >> i;
		s.insert(i);
	}
	if (s.size() == n) cout << "I become the guy.";
	else cout << "Oh, my keyboard!";
}
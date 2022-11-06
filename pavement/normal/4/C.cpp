#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	unordered_map<string, int> m;
	while (n--) {
		cin >> s;
		if (!m[s]) cout << "OK\n";
		else cout << s << m[s] << '\n';
		m[s]++;
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a = 0;
	map<string, int> m;
	m["Tetrahedron"] = 4;
	m["Cube"] = 6;
	m["Octahedron"] = 8;
	m["Dodecahedron"] = 12;
	m["Icosahedron"] = 20;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		a += m[s];
	}
	cout << a;
}
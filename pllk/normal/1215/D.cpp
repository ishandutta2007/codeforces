#include <iostream>

using namespace std;

int n;
string s;
int v[2];
int z[2];

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		int r = i/(n/2);
		if (s[i] == '?') {
			v[r]++;
		} else {
			z[r] += s[i]-'0';
		}
	}
	while (v[0] && v[1]) {v[0]--; v[1]--;}
	while (v[0]) {v[0] -= 2; z[0] += 9;}
	while (v[1]) {v[1] -= 2; z[1] += 9;}
	if (z[0] == z[1]) cout << "Bicarp\n";
	else cout << "Monocarp\n";
}
#include <iostream>

using namespace std;

int n;
string s;
int z[30][202020];
int m;
int c[30];

bool ok(int k) {
	for (int i = 'a'; i <= 'z'; i++) {
		if (z[i-'a'][k] < c[i-'a']) return false;
	}
	return true;
}

int main() {
	cin >> n;
	cin >> s;
	s = "*"+s;
	for (int k = 'a'; k <= 'z'; k++) {
		int u = k-'a';
		for (int i = 1; i <= n; i++) {
			z[u][i] = z[u][i-1]+(s[i]==k);
		}
	}
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		for (int k = 'a'; k <= 'z'; k++) c[k-'a'] = 0;
		for (auto x : s) c[x-'a']++;
		int u = 0;
		for (int b = n; b >= 1; b /= 2) {
			while (u+b <= n && !ok(u+b)) u += b;
		}
		cout << u+1 << "\n";
	}
}
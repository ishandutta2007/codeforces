#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0, len = a.length(); i < len; i++) { a[i] = tolower(a[i]); b[i] = tolower(b[i]); }
	a.compare(b) == 0 ? cout << 0 : a > b ? cout << 1 : cout << -1;
}
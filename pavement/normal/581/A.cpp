#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << min(a, b) << " ";
	int c = max(a, b);
	c -= min(a, b);
	cout << c / 2;
}
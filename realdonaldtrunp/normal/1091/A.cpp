#include"bits/stdc++.h"
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a += 2;
	b += 1;
	int f = min(a, min(b, c));
	f *= 3;
	f -= 3;
	cout << f << endl;
	return 0;
}
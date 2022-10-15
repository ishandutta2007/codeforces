#include <iostream>

using namespace std;

int x, y, z;
int a, b, c;

int main() {
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	a -= x;
	bool ok = true;
	if (a < 0) ok = false;
	int r = a+b;
	if (r < y) ok = false;
	r -= y;
	r += c;
	if (r < z) ok = false;
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}
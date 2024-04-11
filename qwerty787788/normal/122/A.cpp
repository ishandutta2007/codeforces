#include <iostream>
#include <cmath>
using namespace std;
//
int n;
bool ok = false;
//
void gen(int x) {
	if (n % x == 0) ok = true; else {
		if (x < 1000) {
			gen(x*10+4);
			gen(x*10+7);
		}
	}
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	gen(4);
	gen(7);
	if (ok) cout << "YES"; else
		cout << "NO";
	//
	return 0;
}
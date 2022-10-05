#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int a, b, i; cin >> a >> b;
	for (i = 1; i < a + 1; i++) cout << i << " ";
	cout << a + b + 1 << " ";
	for (i = a + b; i > a; i--) cout << i << " ";
}
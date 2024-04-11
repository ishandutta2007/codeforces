#include <iostream>

using namespace std;

bool pass[101];

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++) pass[i] = false;
	int k;
	int a; cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> k; pass[k] = true;
	}
	int b; cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> k; pass[k] = true;
	}
	bool ok = true;
	for (int i = 1; i <= n; i++) if (!pass[i]) ok = false;
	cout << ((ok) ? "I become the guy." : "Oh, my keyboard!") << endl;
}
#include <iostream>

using namespace std;

int n;
int a[20];
bool ok;

void lol(int x, int k) {
	if (x < 0) x += 360;
	if (x >= 360) x -= 360;
	if (k == n+1) {
		if (x == 0) ok = true;
		return;
	}
	lol(x+a[k],k+1);
	lol(x-a[k],k+1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	lol(0,1);
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}
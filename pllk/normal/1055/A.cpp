#include <iostream>

using namespace std;

int n, s;
int a[1111];
int b[1111];

void end(int x) {
	if (x == 0) cout << "NO\n";
	else cout << "YES\n";
	exit(0);
}

int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	if (a[1] == 0) end(0);
	if (a[s] == 1) end(1);
	if (b[s] == 0) end(0);
	for (int i = n; i >= 1; i--) {
		if (a[i] && b[i]) {
			if (i >= s) end(1);
		}
	}
	end(0);
}
#include <iostream>

using namespace std;

int x[] = {0,2,3,5,7,11,13,17,19,23,29,31};

int a[1111];
int c[1111];
int r[1111];

void lol() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int u = 0;
	for (int i = 1; i <= 11; i++) r[i] = 0;
	for (int i = 1; i <= n; i++) {
		c[i] = 1;
		for (int j = 1; j <= 11; j++) {
			if (a[i]%x[j] == 0) {
				if (r[j] == 0) r[j] = ++u;
				c[i] = r[j];
				break;
			}
		}
	}
	cout << u << "\n";
	for (int i = 1; i <= n; i++) cout << c[i] << " ";
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}
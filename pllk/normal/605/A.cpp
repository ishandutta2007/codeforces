#include <iostream>

using namespace std;

int n;
int p[101010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p[x] = i;
	}
	int v = 0;
	int c = 0;
	int z = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] > v) {
			c++;
		} else {
			c = 1;
		}
		v = p[i];
		z = max(z,c);
	}
	cout << n-z << "\n";
}
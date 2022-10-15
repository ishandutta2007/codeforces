#include <iostream>
#include <cstdlib>

using namespace std;

int m, n;
int z[50];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cout << m << endl;
		int x;
		cin >> x;
		if (x == 0) exit(0);
		if (x == 1) z[i] = 1;
	}
	int a = 1;
	int b = m;
	int i = 1;
	while (true) {
		int k = (a+b)/2;
		cout << k << endl;
		int x;
		cin >> x;
		if (z[i]) x = -x;
		i++;
		if (i > n) i = 1;
		if (x == 0) exit(0);
		if (x == -1) b = k-1;
		else a = k+1;
	}
}
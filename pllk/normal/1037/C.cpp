#include <iostream>

using namespace std;

int n;
string a, b;
int c;

int main() {
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n-1; i++) {
		if (a[i] != a[i+1] && a[i] != b[i] && a[i+1] != b[i+1] &&
		    a[i] == b[i+1] && a[i+1] == b[i]) {
			swap(a[i],a[i+1]);
			c++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) c++;
	}
	cout << c << "\n";
}
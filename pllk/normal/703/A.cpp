#include <iostream>

using namespace std;

int n;
int c;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) c++;
		if (a < b) c--;
	}
	if (c > 0) cout << "Mishka\n";
	if (c < 0) cout << "Chris\n";
	if (c == 0) cout << "Friendship is magic!^^\n";
}
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int a = 0;
	int b = 0;
	for (auto c : s) {
		if (c == 'a') a++;
		else b++;
	}
	while (a*2 <= a+b) b--;
	cout << a+b << "\n";
}
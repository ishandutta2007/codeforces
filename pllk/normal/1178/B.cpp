#include <iostream>

using namespace std;

typedef long long ll;

string s;
int n;
ll a, b, c;


int main() {
	cin >> s;
	n = s.size();
	for (int i = 1; i < n; i++) {
		if (s[i-1] == 'v' && s[i] == 'v') {
			a++;
			c += b;
		}
		if (s[i] == 'o') {
			b += a;
		}
	}
	cout << c << "\n";
}
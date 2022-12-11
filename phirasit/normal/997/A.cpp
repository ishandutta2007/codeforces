#include <iostream>

using namespace std;

int main() {

	int n;
	long long x, y;
	cin >> n >> x >> y;

	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (i == 0 || str[i-1] == '1') && str[i] == '0';
	}

	if (ans == 0) {
		cout << 0 << endl;
	} else {
		long long out = min(x * (ans-1) + y, y * ans); 
		cout << out << endl;
	}
}
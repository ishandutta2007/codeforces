#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	if (n == 1) {
		cout << "Yes\n";
		return 0;
	}
	sort(s.begin(),s.end());
	for (int i = 1; i < n; i++) {
		if (s[i-1] == s[i]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}
#include <iostream>
#include <algorithm>

using namespace std;

void lol() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	if (s[0] == s[k-1]) {
		if (s[k] == s[n-1]) {
			for (int i = 0; i < n; i++) {
				if (i%k == 0) cout << s[i];
			}
			cout << "\n";
		} else {
			for (int i = k-1; i < n; i++) {
				cout << s[i];
			}
			cout << "\n";
		}
	} else {
		cout << s[k-1] << "\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}
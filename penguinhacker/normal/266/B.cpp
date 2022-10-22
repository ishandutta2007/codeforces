#include <bits/stdc++.h>
using namespace std;

int n, t;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t >> s;
	while (t--) {
		for (int i=0; i<n-1; ++i) {
			if (s[i]=='B'&&s[i+1]=='G') {
				swap(s[i], s[i+1]);
				i++;
			}
		}
	}
	cout << s;
	return 0;
}
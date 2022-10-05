#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int n, bynow = 0, mx = 1, next, ans = 0, j;
	string s, b[50];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	cin >> s;
	while (bynow < s.size() && mx > 0) {
		mx = 0;
		for (int i = 0; i < n; i++) {
			next = bynow, j = -1;
			while (++j < b[i].size() && next < s.size())
				if (b[i][j] == s[next]) next++;
			mx = max(mx, next - bynow);
		}
		bynow += mx, ans++;
	}
	cout << (bynow < s.size() ? -1 : ans) << endl;
}
#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include <tuple>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool beau = true;
	for (int i = k; i < 2 * k; ++i) {
		for (int j = i; j < n; j += k) {
			if (s[j] != s[j - k])beau = false;
		}
	}
	if (beau) {
		cout << n << "\n" << s;
		return 0;
	}
	int change = 1;

	for (int j = k; j < n; ++j) {
		if (s[j] < s[j - k]) {
			change = 0;
			break;
			}
		if (s[j] > s[j - k]) {
			change = 3;
			break;
		}
	}
	if (change > 2) {
		for (int i = k - 1; i >= 0; --i) {
			if (s[i] < '9') {
				++s[i];
				for (int j = i + 1; j < k; ++j)s[j] = '0';
				break;
			}
		}
	}
	for (int i = k; i < 2 * k; ++i) {
		for (int j = i; j < n; j += k) {
			s[j] = s[j - k];
		}
	}
	cout << n << "\n" << s;
	return 0;
}
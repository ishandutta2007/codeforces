#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	char op;
	vector<int> one(10, 1);
	vector<int> zero(10, 0);
	
	int n, x;
	cin >> n;
	while (n--) {
		cin >> op >> x;
		if (op == '|') {
			for (int i = 0; i < 10; i++) {
				int bit = x & (1 << i);
				if (bit) {
					one[i] = 1;
					zero[i] = 1;
				}
			}
		} else if (op == '&') {
			for (int i = 0; i < 10; i++) {
				int bit = x & (1 << i);
				if (bit == 0) {
					one[i] = 0;
					zero[i] = 0;
				}
			}
		} else {
			for (int i = 0; i < 10; i++) {
				int bit = x & (1 << i);
				if (bit) {
					one[i] ^= 1;
					zero[i] ^= 1;
				}
			}
		}
	}
	
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < 10; i++) {
		if (one[i] == zero[i]) {
			ans2 += one[i] << i;
		} else {
			ans1 += 1 << i;
			ans2 += zero[i] << i;
		}
	}
	cout << "2\n& " << ans1 << "\n^ " << ans2;
	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n;
int cnt = 0;
int mask = 0;
int has = 0;
int res = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		char op;
		string s;
		cin >> op >> s;
		if (__builtin_popcount(mask) == 25) {
			has = 1;
		}
		if (has == 1 && (op == '!' || op == '?')) res++;
		if (op == '.') {
			int now = 0;
			for (char u : s) {
				now |= 1 << (u - 'a');
			}
			mask |= now;
		}
		if (op == '!') {
			int now = 0;
			for (char u : s) {
				now |= 1 << (u - 'a');
			}
			now ^= (1 << 26) - 1;
			mask |= now;
		}
		if (op == '?') {
			mask |= (1 << (s[0] - 'a'));
		}
	}
	cout << res << endl;
	return 0;
}
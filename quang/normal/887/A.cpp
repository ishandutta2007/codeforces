#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	int pos = -1;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') cnt++;
		if (cnt == 6) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		puts("no");
		return 0;
	}
	for (int i = pos - 1; i >= 0; i--) {
		if (s[i] == '1') {
			puts("yes");
			return 0;
		}
	}
	puts("no");
	return 0;
}
#include <bits/stdc++.h>

std::string str;
bool flag[5100][5100];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> str;
	for (int i = 0; i < str.size (); ++i) {
		int cnt = 0;
		for (int j = i; j < str.size (); ++j) {
			if (str[j] == '(') ++cnt;
			if (str[j] == '?') ++cnt;
			if (str[j] == ')') --cnt;
			if (cnt < 0) break;
			if ((j - i) % 2 == 1) flag[i][j] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < str.size (); ++i) {
		int cnt = 0;
		for (int j = i; j >= 0; --j) {
			if (str[j] == '(') --cnt;
			if (str[j] == '?') ++cnt;
			if (str[j] == ')') ++cnt;
			if (cnt < 0) break;
			if ((i - j) % 2 == 1 && flag[j][i]) ++ans;
		}
	}
	std::cout << ans << std::endl;
}
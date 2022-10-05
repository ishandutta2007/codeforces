#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	char l, ans[2][13];
	for (int i = 0; i < 2; i++) for (int j = 0; j < 13; j++) ans[i][j] = '0';
	int ind[2], dis, left, right, p = 0;
	string s;
	vector<int> loc(26, -1);
	cin >> s;
	for (int i = 0; i < 27; i++) {
		if (loc[s[i] - 'A'] == -1)
			loc[s[i] - 'A'] = i;
		else {
			ind[0] = loc[s[i] - 'A'], ind[1] = i, l = s[i], dis = ind[1] - ind[0];
			break;
		}
	}
	while (s[0] != l) {
		char t = s[0];
		for (int i = 0; i < 26; i++) s[i] = s[i + 1];
		s[26] = t;
	}
	ind[0] = 0, ind[1] = dis;
	if (dis == 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	ans[0][(dis - 1) / 2] = l;
	left = (dis - 1) / 2, right = 12 - left;
	for (int i = ind[0]; i > 0; i--) ans[i > right ? 1 : 0][12 - abs(i - right)] = s[p++];
	p++;
	for (int i = (dis - 1) / 2 - 1; i >= 0; i--) ans[0][i] = s[p++];
	for (int i = 0; i < 13 && ans[1][i] == '0'; i++) {
		if (s[p] == l) p++;
		ans[1][i] = s[p++];
	}
	if (p < 27)
		for (int i = 12; ans[0][i] == '0'; i--) ans[0][i] = s[p++];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 13; j++) cout << ans[i][j];
		cout << endl;
	}
}
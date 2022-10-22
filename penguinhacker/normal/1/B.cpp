#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int row, col, type;
string s;

void detType() {
	//type 1 such at BC23
	bool seenNum = 0;
	for (char c : s) {
		if (!seenNum && '0'<=c && c<='9')
			seenNum = 1;
		if (seenNum && 'A'<=c && c<='Z') {
			type = 2;
			return;
		}
	}
	type = 1;
}

void toStr(int c, string result="") {
	if (c == 0) {
		cout << result;
		return;
	}
	c--;
	char add = 'A'+(c%26);
	result = add+result;
	c /= 26;
	toStr(c, result);
}

void solve() {
	cin >> s;
	detType();
	if (type == 1) {
		row = 0; col = 0;
		for (char c : s) {
			if ('A'<=c && c<='Z')
				col = 26*col + c-'A'+1;
			else
				row = 10*row + c-'0';
		}
		cout << 'R' << row << 'C' << col << '\n';
	}
	else {
		col = 0;
		row = 0;
		bool seenC = 0;
		for (int i=1; i<s.size(); ++i) {
			if (s[i] == 'C')
				seenC = 1;
			else if (!seenC)
				row = 10*row + s[i]-'0';
			else
				col = 10*col + s[i]-'0';
		}
		toStr(col);
		cout << row << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
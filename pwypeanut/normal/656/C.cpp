#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	long long ans = 0;
	for (int i = 0; i < s.length(); i++) {
		int alpha;
		if (s[i] == '.') alpha = 0;
		else alpha = tolower(s[i]) - 'a' + 1;
		ans += (int)(s[i] > '@' && s[i] < '[') * (alpha) - (int)(s[i] > '`' && s[i] < '{') * (alpha);
	}
	cout << ans << endl;
}
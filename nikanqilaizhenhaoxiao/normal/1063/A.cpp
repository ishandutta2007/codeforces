#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	cin >> s;
	sort(s.begin(), s.end(), [&](char a, char b) { return a < b; });
	cout << s << endl;
	return 0;
}
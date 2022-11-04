#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	bool ok = false;
	cin >> s;
	for (int i = 0; i < (int)((int)s.length() - 6); ++i) {
		if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0' && s[i + 3] == '0' && s[i + 4] == '0' && s[i + 5] == '0' && s[i + 6] == '0') {
			ok = true;
			break;
		}
		if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1' && s[i + 3] == '1' && s[i + 4] == '1' && s[i + 5] == '1' && s[i + 6] == '1') {
			ok = true;
			break;
		}
	}
	if (ok)cout << "YES";
	else cout << "NO";
	return 0;
}
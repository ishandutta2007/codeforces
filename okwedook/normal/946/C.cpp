#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	char ptr = 'a';
	for (int i = 0; i < s.size(); ++i)
		if (s[i] <= ptr && ptr <= 'z') s[i] = ptr, ++ptr;
	if (ptr > 'z') cout << s;
	else cout << -1;
	return 0;
}
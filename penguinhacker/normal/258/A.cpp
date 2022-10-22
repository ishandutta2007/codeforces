#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	bool hasZero=0;
	for (int i=0; i<s.size(); ++i) {
		if (s[i]=='0') {
			s.erase(s.begin()+i);
			hasZero=1;
			break;
		}
	}
	if (!hasZero) s.erase(s.begin());
	cout << s;
	return 0;
}
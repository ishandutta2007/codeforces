#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2, t;
	cin >> s1 >> s2 >> t;
	int a[26];
	for (int i = 0; i < s1.size(); i++) a[s1[i] - 'a'] = int(s2[i]);
	for (int i = 0; i < t.size(); i++)
		cout << (t[i] < 'A' ? t[i] : char(a[t[i] % 32 - 1] - (t[i] < 'a' ? 32 : 0)));
	return 0;
}
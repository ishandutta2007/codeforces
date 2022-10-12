#include <bits/stdc++.h>
using namespace std;

int main () {
	string s;
	cin >> s;
	
	int i = 0;
	
	while (s[i] == 'a') i++;

    if (i == s.length()) s[i-1] += 25;
	
	while (i < s.length () && s[i] != 'a')
		s[i]--, i++;
	
	cout << s << endl;
	return 0;
}
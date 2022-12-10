#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s >> s;
	for(int i = 0; i < s.size(); i++)
		s[i] = (s[i] <= 'z' and s[i] >= 'a') ? s[i] : s[i] - 'A' + 'a';
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());
	if(s.size() == 26)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
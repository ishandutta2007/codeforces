#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	map<string, int> m;
	
	string s;
	while (n--) {
		cin >> s;
		sort(s.begin(), s.end());
		
		s += ' ';
		string x = "";
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] != s[i + 1]) {x += s[i];}
		}
		m[x] = 69;
	}
	
	cout << m.size();
	
	return 0;
}
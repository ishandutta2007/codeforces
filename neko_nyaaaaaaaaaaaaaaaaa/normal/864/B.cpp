#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> a(0);
	string tmp;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {tmp += s[i]; continue;}
		else {
			a.push_back(tmp);
			tmp.resize(0);
		}
	}
	a.push_back(tmp);
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		vector<int> b(26, 0);
		for (int j = 0; j < a[i].size(); j++) {
			b[a[i][j] - 'a']++;
		}
		int ss = 0;
		for (int j = 0; j < 26; j++) {
			if (b[j]) {ss++;}
		}
		if (ss > ans) ans = ss;
	}
	cout << ans;
	
	return 0;
}
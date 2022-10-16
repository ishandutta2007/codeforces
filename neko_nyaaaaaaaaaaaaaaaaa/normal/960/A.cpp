#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	vector<int> a(3, 0);
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
	}
	
	string x = s;
	sort(x.begin(), x.end());
	if (x != s) {cout << "NO"; return 0;}
	if (a[0] == 0 || a[1] == 0 || a[2] == 0) {cout << "NO"; return 0;}
	if (a[0] != a[2] && a[1] != a[2]) {cout << "NO"; return 0;}
	cout << "YES";
	
	return 0;
}
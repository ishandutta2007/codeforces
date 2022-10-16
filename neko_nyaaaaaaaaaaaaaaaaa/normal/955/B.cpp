#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	if (s.size() <= 3) {cout << "NO"; return 0;}
	vector<int> a(26, 0);
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
	}
	int cnt = 0;
	int one = 0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > 0) {cnt++;}
		if (a[i] == 1) {one++;}
	}
	if (cnt >= 5) {cout << "NO"; return 0;}
	if (one == 1 && cnt == 2) {cout << "NO"; return 0;}
	if (cnt == 1) {cout << "NO"; return 0;}

	cout << "YES";
	
	return 0;
}
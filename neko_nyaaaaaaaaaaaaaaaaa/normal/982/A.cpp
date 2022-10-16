#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	if (n == 1) {
		if (s[0] == '0') {cout << "No";}
		else {cout << "Yes";}
		return 0;
	}
	
	for (int i = 1; i < n; i++) {
		if (s[i] == '1' && s[i-1] == '1') {cout << "No"; return 0;}
	}
	
	if (s[0] == '0' && s[1] == '0') {cout << "No"; return 0;}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {cnt++;}
		else {
			if (cnt > 2) {cout << "No"; return 0;}
			cnt = 0;
		}
	}
	if (cnt >= 2) {cout << "No"; return 0;}
	
	cout << "Yes";
	
	return 0;
}
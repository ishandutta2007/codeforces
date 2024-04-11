#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	
	bool flag = 1;
	for (int i = 0; i < n - p; i++) {
		if ((s[i] != s[i+p]) || (s[i] == '.' && s[i+p] == '.')) {
			flag = 0;
			if (s[i] == '1' && s[i+p] == '.') {s[i+p] = '0'; continue;}
			if (s[i] == '0' && s[i+p] == '.') {s[i+p] = '1'; continue;}
			if (s[i] == '.' && s[i+p] == '1') {s[i] = '0'; continue;}
			if (s[i] == '.' && s[i+p] == '0') {s[i] = '1'; continue;}
			if (s[i] == '.' && s[i+p] == '.') {s[i] = '1'; s[i+p] = '0'; continue;}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {s[i] = '1';}
	}
	
	if (flag) {cout << "No";}
	else {cout << s;}
	
	return 0;
}
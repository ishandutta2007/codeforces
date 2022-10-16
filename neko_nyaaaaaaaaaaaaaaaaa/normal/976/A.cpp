#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int z = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') z++;
	}
	
	if (n == 1) {cout << s; return 0;}
	
	cout << 1;
	
	for (int i = 0; i < z; i++) {
		cout << 0;
	}
	
	return 0;
}
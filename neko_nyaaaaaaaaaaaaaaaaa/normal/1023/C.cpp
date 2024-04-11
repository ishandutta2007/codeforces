#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int op = 0;
	int cs = 0;
	int opk = k/2, csk = k/2;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			op++; 
			if (opk) {cout << '('; opk--;}
		} else {
			op--;
			if (csk) {cout << ')'; csk--;}
		}
	}
	
	return 0;
}
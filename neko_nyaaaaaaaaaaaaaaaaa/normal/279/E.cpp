#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string s;
	cin >> s;
	int ans = 0;
	s = "00" + s;
	for (int i = s.size() - 1; i; i--) {
		if (s[i] == '0') {continue;}
		if (s[i-1] == '0') {ans++; continue;}
            while (s[i] == '1') {i--;}
            s[i] = '1';
            i++;
            ans++;
	}
	cout << ans;
	
	return 0;
}
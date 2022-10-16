#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	if (n == 1) {cout << "Yes"; return 0;}
	string s; cin >> s;
	map<char, int> m;
	for (int i = 0; i < n; i++) {
		m[s[i]]++;
		if (m[s[i]] > 1) {cout << "Yes"; return 0;}
	}
	cout << "No";
	
	return 0;
}
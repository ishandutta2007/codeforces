#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
map < string, ll > m; string s1, s2, x; ll n, y = 1;

int main () {
	cin >> n;
	m["polycarp"] = 1;
	for (ll j = 1; j <= n; j++){
		cin >> s1 >> x >> s2;
		for (ll i = 0; i <= s1.length(); i++){
			s1[i] = tolower(s1[i]);
		}
		for (ll i = 0; i <= s2.length(); i++){
			s2[i] = tolower(s2[i]);
		}
		y = max (m[s2] + 1, y);
		m[s1] = m[s2] + 1;
	}
	cout << y << endl;
}
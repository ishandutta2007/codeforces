/** neko_nyaa's very long and elaborated template **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int k;
	cin >> k;
	string s;
	if (k == 1) {cout << 6; return 0;}
	if (k > 36) {cout << -1; return 0;}
	while (k > 1) {
		s += '8';
		k -= 2;
	}
	if (k == 1) {s += '0';}
	cout << s;
	
	
	return 0;
}
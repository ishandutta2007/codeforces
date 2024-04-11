#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	ll n, m, a, b;
	cin >> n >> m;
	ll cur = 0;
	while (n--) {
		if (cur >= m) {cout << "YES"; return 0;}
		cin >> a >> b;
		if (a <= cur) {
			cur = max(cur, b);
		}
	}
	
		if (cur >= m) {cout << "YES"; return 0;}
	cout << "NO";
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, x, count = 0;
	cin >> n >> x;
	while (n--) {
		char c; ll a;
		cin >> c >> a;
		if (c == '+') {x += a; continue;}
		if (c == '-') {
			if (a <= x) {x -= a; continue;}
			else {count++;}
		}
	}
	cout << x << " " << count;
	
	return 0;
}
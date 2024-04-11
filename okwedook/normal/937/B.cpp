#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p, y;

bool check(ll a) {
	ll i = 2;
	while (i <= p && i * i <= a) {
		if (a % i == 0) return true;
		++i;
	}
	return false;
}

int main() {
	cin >> p >> y;
	while (y > p && check(y)) --y;
	if (y <= p) cout << -1;
	else cout << y;	 
    return 0;
}
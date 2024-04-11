#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	cin >> n;
	if (n == 0) {cout << n; return 0;}
	n++;
	if (n % 2 == 0) {
		n /= 2;
	}
	cout << n;
	
	return 0;
}
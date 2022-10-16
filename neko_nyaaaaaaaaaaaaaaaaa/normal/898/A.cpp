#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() { 
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n;
	cin >> n;
	if (n % 10 == 0) {cout << n; return 0;}
	if (n % 10 < 5) {cout << n - (n%10); return 0;}
	if (n % 10 >= 5) {
		n += 10;
		cout << n - (n%10); return 0;
	}
	
	return 0;
}
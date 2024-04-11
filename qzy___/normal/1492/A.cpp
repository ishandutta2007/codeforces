#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
ll a, b, c, p;

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> p >> a >> b >> c;
		ll A = 8000000000000000000;
		if(p % a == 0) A = 0;
		else A = min(A, (p / a + 1) * a - p);
		if(p % b == 0) A = 0;
		else A = min(A, (p / b + 1) * b - p);
		if(p % c == 0) A = 0;
		else A = min(A, (p / c + 1) * c - p);
		cout << A << endl;
	}
	return 0;
}
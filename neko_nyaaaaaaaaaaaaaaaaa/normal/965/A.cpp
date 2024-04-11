#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int k, n, s, p;
	cin >> k >> n >> s >> p;
	
	int need;
	if (n % s == 0) {
		need = n/s;
	} else {
		need = n/s + 1;
	}
	
	need *= k;
	
	if (need % p == 0) {
		cout << need/p;
	} else {
		cout << need/p + 1;
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	int x;
	cin >> n;
	while (n--) {
		bool f = false;
		cin >> x;
		for (int i = 0; i <= 15; i++) {
			int tmp = x;
			tmp -= 7*i;
			if (tmp >= 0 && tmp % 3 == 0) {cout << "YES\n"; f=true; break;}
		}
		if (!f) cout << "NO\n";
	}
	
	return 0;
}
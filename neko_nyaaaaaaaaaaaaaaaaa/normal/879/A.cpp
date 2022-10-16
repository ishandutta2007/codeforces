#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = 0; 1; i++) {
			if (x + y*i > ans) {ans = x + y*i; break;}
		}
	}
	cout << ans;
	
	return 0;
}
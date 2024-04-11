#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<=2*n; ++i) {
		for (int j=0; j<=2*n; ++j) {
			int x = n-abs(n-i)-abs(n-j);
			if (x>=0) cout << x;
			else cout << ' ';
			if (j==2*n-abs(n-i)) break;
			if (j<2*n) cout << ' ';
		}
		if (i<2*n) cout << '\n';
	}
	return 0;
}
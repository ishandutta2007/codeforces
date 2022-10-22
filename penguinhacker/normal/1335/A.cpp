#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		if (n<=2)
			cout << 0 << '\n';
		else
			cout << (n-1)/2 << '\n';
	}
	return 0;
}
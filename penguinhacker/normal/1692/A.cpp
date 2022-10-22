#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (b>a)+(c>a)+(d>a) << "\n";
	}
	return 0;
}
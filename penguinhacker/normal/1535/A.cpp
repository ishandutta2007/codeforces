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
		int x=max(a, b), y=max(c, d);
		cout << (min(x, y)>min(a, b)&&min(x, y)>min(c, d)?"YES":"NO") << "\n";
	}
	return 0;
}
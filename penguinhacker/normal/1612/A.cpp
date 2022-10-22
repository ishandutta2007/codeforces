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
		int x, y;
		cin >> x >> y;
		if ((x+y)%2) {
			cout << "-1 -1\n";
			continue;
		}
		if (x>y)
			cout << (x+y)/2 << " " << 0 << "\n";
		else
			cout << 0 << " " << (x+y)/2 << "\n";
	}
	return 0;
}
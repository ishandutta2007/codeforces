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
		if (!a&&!b&&!c&&!d) {
			cout << "0\n";
			continue;
		}
		cout << (a&&b&&c&&d?2:1) << "\n";
	}
	return 0;
}
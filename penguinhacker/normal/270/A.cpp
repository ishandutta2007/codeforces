#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, angle;
	cin >> t;
	while(t--) {
		cin >> angle, angle=180-angle;
		if (360%angle==0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
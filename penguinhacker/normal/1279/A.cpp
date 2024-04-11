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
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		cout << (a[0]+a[1]+1>=a[2]?"Yes":"No") << "\n";
	}
	return 0;
}
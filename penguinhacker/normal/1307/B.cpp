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
		int n, x;
		cin >> n >> x;
		int mx=0;
		bool eq=0;
		while(n--) {
			int a;
			cin >> a;
			mx=max(mx, a);
			eq|=a==x;
		}
		if (eq) {
			cout << "1\n";
			continue;
		}
		cout << max(2, (x+mx-1)/mx) << "\n";
	}
	return 0;
}
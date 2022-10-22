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
		int n;
		cin >> n;
		int c[2]={};
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x;
			++c[x%2];
		}
		cout << min(c[0], c[1]) << "\n";
	}
	return 0;
}
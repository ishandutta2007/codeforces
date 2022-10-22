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
		for (int i=0; i<2*n; ++i) {
			int x;
			cin >> x;
			++c[x%2];
		}
		cout << (c[0]==c[1]?"Yes":"No") << "\n";
	}
	return 0;
}
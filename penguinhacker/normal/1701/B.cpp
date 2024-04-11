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
		cout << "2\n";
		for (int i=1; i<=n; ++i)
			if (i%2) {
				for (int j=i; j<=n; j*=2)
					cout << j << " ";
			}
		cout << "\n";
	}
	return 0;
}
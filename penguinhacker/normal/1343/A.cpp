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
		int k=2;
		while(1) {
			int y=(1<<k)-1;
			if (n%y==0) {
				cout << n/y << '\n';
				break;
			}
			k++;
		}
	}
	return 0;
}
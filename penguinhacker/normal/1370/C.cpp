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
		if (n%2==1) {
			if (n==1) {
				cout << "FastestFinger\n";
			}
			else {
				cout << "Ashishgup\n";
			}
		}
		else {
			if (n==2) {
				cout << "Ashishgup\n";
			}
			else if (__builtin_popcount(n)==1) {
				cout << "FastestFinger\n";
			}
			else {
				int x=n;
				while(x%2==0)
					x/=2;
				bool p=1;
				for (int i=3; i*i<=x; ++i)
					if (x%i==0) {
						p=0;
						break;
					}
				if (!p) {
					cout << "Ashishgup\n";
					continue;
				}
				n/=2;
				if (n%2==1) {
					cout << "FastestFinger\n";
				}
				else {
					cout << "Ashishgup\n";
				}
			}
		}
	}
	return 0;
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
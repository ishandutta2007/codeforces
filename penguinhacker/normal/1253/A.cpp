#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], b[100000], c[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		for (int i=0; i<n; ++i)
			cin >> b[i];
		bool used=0, pos=1;
		for (int i=0; i<n; ++i) {
			if (a[i]>b[i]) {
				pos=0;
				break;
			}
			if (!used&&a[i]==b[i])
				continue;
			if (!used) {
				used=1;
			}
			else {
				if (a[i]==b[i])
					continue;
				if (a[i]-b[i]!=a[i-1]-b[i-1]) {
					pos=0;
					break;
				}
			}
		}
		cout << (pos?"YES":"NO") << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		int x=count(a, a+n, a[0]);
		if (x==1) {
			cout << "1\n";
			continue;
		}
		for (int i=1; i<n; ++i)
			if (a[i]^a[0])
				cout << i+1 << "\n";
	}
	return 0;
}
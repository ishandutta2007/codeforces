#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, a[100];
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		if (n==1 && a[0]%2==1) {
			cout << -1 << '\n';
			continue;
		}
		if (a[0]%2==0)
			cout << 1 << '\n' << 1 << '\n';
		else if (a[1]%2==0)
			cout << 1<< '\n' << 2 << '\n';
		else
			cout << 2 << '\n' << 1 << ' ' << 2 << '\n';
	}
	return 0;
}
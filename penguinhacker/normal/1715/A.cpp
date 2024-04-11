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
		int n, m;
		cin >> n >> m;
		if (n==1||m==1)
			cout << (n==1&&m==1?0:n+m-1) << "\n";
		else
			cout << n-1+m-1+min(n, m) << "\n";
	}
	return 0;
}
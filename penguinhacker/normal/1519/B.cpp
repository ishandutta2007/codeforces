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
		int n, m, k;
		cin >> n >> m >> k;
		int a=m-1+(n-1)*m;
		int b=n-1+(m-1)*n;
		cout << (min(a, b)<=k&&k<=max(a, b)?"YES":"NO") << "\n";
	}
	return 0;
}
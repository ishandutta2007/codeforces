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
		int x;
		cin >> x;
		int b=__builtin_ctz(x);
		if (__builtin_popcount(x)>1)
			cout << (1<<b) << "\n";
		else
			cout << (x==1?3:(1<<b)+1) << "\n";
	}
	return 0;
}
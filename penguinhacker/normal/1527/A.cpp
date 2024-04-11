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
		int x=31-__builtin_clz(n);
		cout << (1<<x)-1 << "\n";
	}
	return 0;
}
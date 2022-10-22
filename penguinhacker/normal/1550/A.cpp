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
		int s=sqrt(x)-1;
		while(s*s<x)
			++s;
		cout << s << "\n";
	}
	return 0;
}
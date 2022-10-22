#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool check(int n) {
	int s=sqrt(n);
	for (int i=max(1, s-2); i<=s+2; ++i)
		if (i*i==n)
			return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ((n%2==0&&check(n/2))||(n%4==0&&check(n/4))?"YES":"NO") << "\n";
	}
	return 0;
}
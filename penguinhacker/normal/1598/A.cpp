#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	bool ok=1;
	for (int i=0; i<n; ++i)
		ok&=a[i]=='0'||b[i]=='0';
	cout << (ok?"YES":"NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
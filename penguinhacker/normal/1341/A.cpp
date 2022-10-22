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
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int lb=(a-b)*n;
		int rb=(a+b)*n;
		lb=max(lb, c-d);
		rb=min(rb, c+d);
		cout << (lb<=rb?"Yes":"No") << '\n';
	}
	return 0;
}
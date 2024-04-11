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
		ll a, b, x;
		cin >> a >> b >> x;
		if (x==a||x==b) {
			cout << "YES\n";
			continue;
		}
		if (a<b)
			swap(a, b);
		bool ok=0;
		while(b) {
			if (x>a)
				break;
			if (x>=b&&(a-x)%b==0) {
				ok=1;
				break;
			}
			a%=b;
			swap(a, b);
		}
		cout << (ok?"YES":"NO") << "\n";
	}
	return 0;
}
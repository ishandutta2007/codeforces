#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	while(1) {
		if (min(n, m)==0||max(n, m)<2*min(n, m))
			break;
		//cout << n << " " << m << endl;
		if (n>m) {
			ll d=n-2*m;
			n-=d/(2*m)*2*m;
			n-=2*m;
		} else {
			ll d=m-2*n;
			m-=d/(2*n)*2*n;
			m-=2*n;
		}
	}
	cout << n << " " << m;
	return 0;
}
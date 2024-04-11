#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<bool> taken(n);
		bool b=1;
		for (int i=0; i<n; ++i) {
			ll k;
			cin >> k, k+=1ll*2e9*n;
			ll spot=(i+k)%n;
			if (taken[spot])
				b=0;
			taken[spot]=1;
		}	
		cout << (b?"YES":"NO") << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkprime(long long k) {
      if (k == 2) return 1;
      if (k % 2 == 0) return 0;
      for (long long i = 3; i <= sqrt(k); i+=2) {
            if (k % i == 0) return 0;
      }
      return 1;
}

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m;
	cin >> n >> m;
	ll ans = n;
	while (!checkprime(ans)) {
		ans++;
	}
	cout << ans << " " << ans << "\n";
	map<pair<ll, ll>, bool> flag;
	for (ll i = 1; i < n-1; i++) {
		pair<ll, ll> k = make_pair(i, i+1);
		flag[k] = 1;
		cout << i << " " << i+1 << " 1\n";
	}
	cout << n-1 << " " << n << " " << ans-n+2 << "\n";
	m -= n;
	m++;
	if (m == 0) {return 0;}
	for (ll i = 1; i <= n; i++) {
		if (m == 0) {return 0;}
		for (ll j = i+1; j <= n; j++) {
			pair<ll, ll> k = make_pair(i, j);
			if (flag[k]) {continue;}
			else {
				cout << i << " " << j << " 1000000000\n";
				m--;
				flag[k] = 1;
			}
			if (m == 0) {return 0;}
		}
	}
	
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<ll> factor(ll n) {
	vector<ll> f;
	for (int i=1; i*i<=n; ++i) {
		if (n%i)
			continue;
		f.push_back(i);
		if (i*i<n)
			f.push_back(n/i);
	}
	sort(f.begin(), f.end());
	return f;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		bool ok=0;
		vector<ll> fa=factor(a), fb=factor(b);
		ll ab=a*b;
		for (ll i : fa) {
			for (ll j : fb) {
				ll ij=i*j;
				if (ij>c||ab/ij>d)
					continue;
				ll x=(a/ij+1)*ij;
				ll y=(b/(ab/ij)+1)*(ab/ij);
				if (x<=c&&y<=d) {
					cout << x << " " << y << "\n";
					ok=1;
					break;
				}
			}
			if (ok)
				break;
		}
		if (!ok)
			cout << "-1 -1\n";
	}
	return 0;
}
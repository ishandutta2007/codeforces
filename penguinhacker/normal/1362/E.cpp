#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;

ll bp(ll b, int p) {
	ll r=1;
	for (; p; p>>=1, b=b*b%M)
		if (p&1)
			r=r*b%M;
	return r;
}

void solve() {
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	sort(a.begin(), a.end());
	ar<ll, 2> cur={a[n-1], 1};
	ll ans=bp(p, a[n-1]);
	for (int i=n-2; ~i; --i) {
		if (cur[1]==0||p==1)
			cur[0]=a[i];
		while(cur[0]>a[i]) {
			--cur[0], cur[1]*=p;
			if (cur[1]>n) {
				for (int j=i; ~j; --j)
					ans=(ans+M-bp(p, a[j]))%M;
				cout << ans << "\n";
				return;
			}
		}
		if (cur[1]==0) {
			ans=(ans+bp(p, a[i]))%M;
			++cur[1];
		} else {
			ans=(ans+M-bp(p, a[i]))%M;
			--cur[1];
		}
	}
	cout << ans << "\n";
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
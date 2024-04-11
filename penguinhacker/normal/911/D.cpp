#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[1500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	int ans=0;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			ans+=a[i]>a[j];
	ans%=2;
	cin >> m;
	for (int i=0; i<m; ++i) {
		int l, r;
		cin >> l >> r;
		int x=r-l+1;
		x=x*(x-1)/2;
		ans=(ans+x)%2;
		cout << (ans?"odd":"even") << "\n";
	}
	return 0;
}
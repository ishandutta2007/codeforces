#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100], b[100], c[100], d[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	ar<int, 2> ans={6969, -1};
	for (int i=0; i<n; ++i) {
		bool bad=0;
		for (int j=0; j<n; ++j)
			bad|=a[j]>a[i]&&b[j]>b[i]&&c[j]>c[i];
		if (!bad)
			ans=min(ans, {d[i], i+1});
	}
	cout << ans[1];
	return 0;
}
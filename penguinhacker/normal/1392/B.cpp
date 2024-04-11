#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];
ll k;
void test_case() {
	cin >> n >> k;
	int mx=-2e9;
	int mn=2e9;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		mx=max(mx, a[i]);
		mn=min(mn, a[i]);
	}
	if (k%2==1) {
		for (int i=0; i<n; ++i)
			a[i]=mx-a[i];
	}
	else {
		for (int i=0; i<n; ++i)
			a[i]-=mn;
	}
	for (int i=0; i<n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
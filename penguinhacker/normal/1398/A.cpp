#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[50000];

void test_case() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (a[0]+a[1]>a[n-1]) cout << "-1\n";
	else cout << "1 2 " << n << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
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
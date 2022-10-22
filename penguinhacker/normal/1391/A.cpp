#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void test_case() {
	int n;
	cin >> n;
	for (int i=1; i<=n; ++i)
		cout << i << ' ';
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
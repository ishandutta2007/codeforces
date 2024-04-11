#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
string g[100];

void test_case() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	int ans=0;
	for (int i=0; i<m-1; ++i)
		if (g[n-1][i]=='D')
			++ans;
	for (int i=0; i<n-1; ++i)
		if (g[i][m-1]=='R')
			++ans;
	cout << ans << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a=k/n, b=k%n;
		cout << (b==0?0:2) << '\n';
		vector<string> s(n, string(n, '0'));
		for (int i=0; i<n; ++i)
			for (int j=i; j<i+a+(i<b); ++j)
				s[i][j%n]='1';
		for (string t : s)
			cout << t << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
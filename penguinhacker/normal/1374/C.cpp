#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cin >> s;
		int d=0, l=0;
		for (char c : s) {
			d+=(c=='('?1:-1);
			l=min(l, d);
		}
		cout << -l << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; ++i)
			cin >> a[i];
		string s(100, 'a');
		cout << s << '\n';
		for (int i=0; i<n; ++i) {
			s[a[i]]=s[a[i]]=='a'?'b':'a';
			cout << s << '\n';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
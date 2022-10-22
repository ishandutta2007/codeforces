#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int calc(int n, string s, char c) {
	assert(n==s.size());
	if (n==1) return s[0]!=c;
	n/=2;
	int a1=n-count(s.begin(), s.begin()+n, c)+calc(n, s.substr(n, n), c+1);
	int a2=n-count(s.begin()+n, s.end(), c)+calc(n, s.substr(0, n), (char)(c+1));
	return min(a1, a2);
}

void solve() {
	int n; string s;
	cin >> n >> s;
	cout << calc(n, s, 'a') << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
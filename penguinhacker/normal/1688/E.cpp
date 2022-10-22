#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
ar<int, 2> e[500];

int qry(string s) {
	cout << "? " << s << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		string s(m, '0');
		s[i]='1';
		e[i][0]=qry(s), e[i][1]=i;
	}
	sort(e, e+m);
	ll ans=0;
	string cur(m, '0');
	for (int i=0; i<m; ++i) {
		cur[e[i][1]]='1';
		ll x=qry(cur);
		if (x-ans==e[i][0]) { // good edge
			ans=x;
		} else
			cur[e[i][1]]='0';
	}
	cout << "! " << ans << endl;
	return 0;
}
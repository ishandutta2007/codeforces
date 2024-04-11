#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cnt1, cnt0;
string s, ans;

void solve() {
	cin >> s;
	cnt0=cnt1=0;
	n = s.size();
	for (char c:s) {
		if (c=='0')
			cnt0++;
		else
			cnt1++;
	}
	ans="";
	if (cnt0==0||cnt1==0)
		cout << s << '\n';
	else if (s[0]=='0') {
		string rep="01";
		for (int i=0; i<n; ++i)
			ans+=rep;
		cout << ans << '\n';
	}
	else {
		string rep="10";
		for (int i=0; i<n; ++i)
			ans+=rep;
		cout << ans << '\n';
	}
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
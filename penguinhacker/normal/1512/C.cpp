#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a, b;
string s;

void solve() {
	cin >> a >> b >> s;
	n=s.size();
	for (int i=0; i<n/2; ++i) {
		if (s[i]^'?'&&s[n-i-1]^'?'&&s[i]^s[n-i-1]) {
			cout << "-1\n";
			return;
		}
		if (s[i]^'?'&&s[n-i-1]=='?')
			s[n-i-1]=s[i];
		if (s[n-i-1]^'?'&&s[i]=='?')
			s[i]=s[n-i-1];
	}
	a-=count(s.begin(), s.end(), '0');
	b-=count(s.begin(), s.end(), '1');
	if (a<0||b<0) {
		cout << "-1\n";
		return;
	}
	if (a%2) {
		if (n%2==0||s[n/2]^'?') {
			cout << "-1\n";
			return;
		}
		s[n/2]='0', --a;
	}
	if (b%2) {
		if (n%2==0||s[n/2]^'?') {
			cout << "-1\n";
			return;
		}
		s[n/2]='1', --b;
	}
	if (n%2&&s[n/2]=='?') {
		cout << "-1\n";
		return;
	}
	a/=2, b/=2;
	for (int i=0; i<n/2; ++i) {
		if (s[i]^'?')
			continue;
		if (a)
			s[i]=s[n-i-1]='0', --a;
		else
			s[i]=s[n-i-1]='1';
	}
	cout << s << "\n";
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
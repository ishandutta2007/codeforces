#include <bits/stdc++.h>
using namespace std;

#define ll long long

int sum(string& s) {int res=0; for (int i=0; i<20; ++i) res+=s[i]-'0'; return res;}
void nxt(string& s, long long& ans) {
	int pos;
	ll p=1;
	for (pos=19; ~pos; --pos) {
		if (s[pos]!='0') break;
		p*=10;
	}
	int inc=10-(s[pos]-'0');
	ans+=inc*p;
	s[pos]='0';
	for (int i=pos-1; ~i; --i) {
		if (s[i]=='9') s[i]='0';
		else {
			++s[i];
			break;
		}
	}
}

int s;
string n;
void test_case() {
	cin >> n >> s;
	n=string(20-n.size(), '0')+n;
	//cout << n << "\n";
	ll ans=0;
	while(sum(n)>s) {
		nxt(n, ans);
		//cerr << n << "\n";
		//cerr << sum(n) << "\n";
	}
	//nxt(n, ans);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) test_case();
	return 0;
}
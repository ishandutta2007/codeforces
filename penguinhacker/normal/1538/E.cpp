#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int get(string s) {
	int r=0;
	for (int i=0; i+3<s.size(); ++i)
		r+=s.substr(i, 4)=="haha";
	return r;
}

struct D {
	string pre, suf;
	ll ans;
	D() {ans=0;}
	D(string s) {
		pre=s.size()<=3?s:s.substr(0, 3);
		suf=s.size()<=3?s:s.substr(s.size()-3);
		ans=get(s);
	}
};

D cmb(D a, D b) {
	D res;
	res.ans=a.ans+b.ans+get(a.suf+b.pre);
	res.pre=a.pre+b.pre;
	res.suf=a.suf+b.suf;
	if (res.pre.size()>3)
		res.pre=res.pre.substr(0, 3);
	if (res.suf.size()>3)
		res.suf=res.suf.substr(res.suf.size()-3);
	return res;
}

void solve() {
	int n;
	cin >> n;
	map<string, D> mp;
	ll ans;
	while(n--) {
		string a, t;
		cin >> a >> t;
		if (t==":=") {
			string b;
			cin >> b;
			D x(b);
			ans=x.ans;
			mp[a]=b;
		} else {
			string b, c;
			cin >> b >> c >> c;
			D x=mp[b], y=mp[c];
			D r=cmb(x, y);
			ans=r.ans;
			mp[a]=r;
		}
	}
	cout << ans << "\n";
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
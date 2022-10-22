#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, l;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> s;
	n=s.size();
	auto pr=[&](string t, int rep) {
		for (int i=0; i<rep; ++i)
			cout << t;
		exit(0);
	};
	if (n%l) {
		string t(l, '0');
		t[0]='1';
		pr(t, (n+l-1)/l);
	}
	assert(l<=n);
	string t=s.substr(0, l);
	//check if works already
	for (int i=0; i<n; ++i) {
		if (s[i]==t[i%l]) continue;
		if (s[i]<t[i%l]) pr(t, n/l);
		break;
	}
	for (int i=l-1; ~i; --i)
		if (t[i]<'9') {
			++t[i];
			for (int j=i+1; j<l; ++j)
				t[j]='0';
			pr(t, n/l);
		}
	t=string(l, '0');
	t[0]='1';
	pr(t, n/l+1);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
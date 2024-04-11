#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=998244353;
string a, b;
int n, m, c=0, p[200001];
ll ans=0;

void pad(string &s, string &t) {
	if (s.size()>=t.size()) return;
	string p(t.size()-s.size(), '0');
	s=p+s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p[0]=1;
	for (int i=1; i<=200000; ++i)
		p[i]=p[i-1]*2%MOD;
	cin >> n >> m >> a >> b;
	pad(a, b); pad(b, a);
	n=a.size();
	for (int i=0; i<n; ++i) {
		if (b[i]=='1') ++c;
		if (a[i]=='1') ans=(ans+1ll*c*p[n-i-1])%MOD;
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
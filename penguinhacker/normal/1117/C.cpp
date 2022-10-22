#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

map<char, int> m;
int n, x1, y1, x2, y2;
ll cnt[4], cur[4];
string s;

bool ok(ll k) {
	memset(cur, 0, sizeof(cur));
	for (int i=0; i<4; ++i) cur[i]=k/n*cnt[i];
	for (int i=0; i<k%n; ++i) cur[m[s[i]]]++;
	ll x=x1+cur[1]-cur[3], y=y1+cur[0]-cur[2];
	return abs(x-x2)+abs(y-y2)<=k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	m['U']=0;
	m['R']=1;
	m['D']=2;
	m['L']=3;
	cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
	for (char c : s) cnt[m[c]]++;
	ll l=0, r=2e14;
	while(l<r) {
		ll mid=(l+r)/2;
		if (ok(mid)) r=mid;
		else l=mid+1;
	}
	cout << (l==2e14?-1:l) << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
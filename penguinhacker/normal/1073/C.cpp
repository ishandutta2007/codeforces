#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

map<char, int> m;

int n, ex, ey;
ar<int, 4> ps[200001];
string s;

bool chk(ar<int, 4> x) {
	int rem=n;
	for (int i=0; i<4; ++i) {
		x[i]=ps[n][i]-x[i];
		rem-=x[i];
	}
	int cx=x[1]-x[3], cy=x[0]-x[2];
	return rem>=(abs(ex-cx)+abs(ey-cy));
}

bool ok(int x) {
	ar<int, 4> cur={0, 0, 0, 0};
	for (int i=0; i<x; ++i)
		++cur[m[s[i]]];
	if (chk(cur)) return 1;
	for (int i=x; i<n; ++i) {
		++cur[m[s[i]]], --cur[m[s[i-x]]];
		if (chk(cur))
			return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	m['U']=0;
	m['R']=1;
	m['D']=2;
	m['L']=3;
	cin >> n >> s >> ex >> ey;
	if (abs(ex)+abs(ey)>n||(n-abs(ex)+abs(ey))%2) {
		cout << -1;
		return 0;
	}
	for (int i=0; i<n; ++i) {
		int x=m[s[i]];
		for (int j=0; j<4; ++j)
			ps[i+1][j]=ps[i][j];
		++ps[i+1][x];
	}
	if (chk({0, 0, 0, 0})) {
		cout << 0;
		return 0;
	}
	int l=1, r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if (ok(mid)) r=mid;
		else l=mid+1;
	}
	cout << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
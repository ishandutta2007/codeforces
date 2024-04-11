#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200005;
int n, m, a[mxN], b[mxN];
ll x, y, k;
bool p[mxN];

ll ans=0;
void solve(int l, int r) {
	//cout << l << ' ' << r << '\n';
	int e=max(a[l-1], a[r+1]), sz=r-l+1;
	int mx=0;
	for (int i=l; i<=r; ++i) mx=max(a[i], mx);
	if (sz<k) {
		if (e<mx) {
			cout << -1;
			exit(0);
		}
		ans+=sz*y;
	}
	else {
		ans+=(sz%k)*y;
		sz/=k;
		ans+=(sz-1)*min(y*k, x);
		if (e>mx&&y*k<x) ans+=y*k;
		else ans+=x;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> k >> y;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	for (int i=0; i<m; ++i)
		cin >> b[i];
	int l, r, ind=0;
	for (int i=1; i<=n; ++i) {
		if (ind<m&&a[i]==b[ind]) {
			p[i]=1;
			++ind;
		}
	}
	if (ind!=m) {cout << -1; return 0;}
	p[0]=p[n+1]=1;
	for (int i=1; i<=n+1; ++i) {
		if (p[i]) {
			if (!p[i-1])
				solve(l, r);
		}
		else {
			r=i;
			if (p[i-1])
				l=i;
		}
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
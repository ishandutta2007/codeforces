#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, MOD=998244353;
int n, m, a[mxN], b[mxN];
map<int, int> last;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		last[a[i]]=i;
	}
	for (int i=0; i<m; ++i) {
		cin >> b[i];
	}
	//special
	if (last.begin()->first!=b[0]) {
		cout << 0;
		return 0;
	}
	for (int i=0; i<m; ++i) {
		if (last.find(b[i])==last.end()) {
			cout << 0;
			return 0;
		}
	}
	for (int i=last[b[m-1]]+1; i<n; ++i) {
		if (a[i]<b[m-1]) {
			cout << 0;
			return 0;
		}
	}
	//

	ll ans=1;
	for (int i=0; i+1<m; ++i) {
		int l=last[b[i]], r=last[b[i+1]];
		if (l>=r) {
			assert(l>r);
			cout << 0;
			return 0;
		}
		for (int j=l; j<r; ++j) {
			if (a[j]<b[i]) {
				cout << 0;
				return 0;
			}
			else if (a[j]<b[i+1]) {
				l=j;
			}
		}
		ans=(ans*(r-l))%MOD;
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool ok(int n, int s, int len) {
	return !(s<len*(len+1)/2||s>len*(2*n-len+1)/2);
}

int n, l, r, s, a[500];
bool vis[501];

void solve() {
	memset(vis, 0, sizeof(vis));
	cin >> n >> l >> r >> s, --l, --r;
	int len=r-l+1;
	if (!ok(n, s, len)) {
		cout << "-1\n";
		return;
	}
	int bound=n;
	for (int i=l; i<r; ++i) {
		bool b=0;
		for (int j=bound; j>1; --j)
			if (ok(j-1, s-j, len-1)) {
				assert(!vis[j]);
				bound=j-1, a[i]=j, --len, s-=j, vis[j]=1, b=1;
				break;
			}
		assert(b);
	}
	assert(!vis[s]);
	a[r]=s, vis[s]=1;
	for (int i=0; i<n; ++i) {
		if (i<l||i>r) {
			for (int j=1; j<=n; ++j)
				if (!vis[j]) {
					a[i]=j, vis[j]=1;
					break;
				}
		}
		cout << a[i] << " ";
	}
	cout << "\n";
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
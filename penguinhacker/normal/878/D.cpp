#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, k, q, a[12][mxN];
bitset<1<<12> creature[mxN+12];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> q;
	for (int i=0; i<k; ++i) {
		for (int j=0; j<n; ++j)
			cin >> a[i][j];
		for (int j=0; j<1<<k; ++j)
			creature[i][j]=j>>i&1;
	}
	int n2=k;
	while(q--) {
		int t, x, y;
		cin >> t >> x >> y, --x, --y;
		if (t==1)
			creature[n2++]=creature[x]|creature[y];
		else if (t==2)
			creature[n2++]=creature[x]&creature[y];
		else {
			int ans=0;
			for (int i=0; i<k; ++i) {
				int mask=0;
				for (int j=0; j<k; ++j)
					if (a[j][y]>=a[i][y])
						mask|=1<<j;
				if (creature[x][mask])
					ans=max(ans, a[i][y]);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
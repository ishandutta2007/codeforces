#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> l(n), r(n), c(n);
		int bl=0, br=0, bb=0;
		for (int i=0; i<n; ++i) {
			cin >> l[i] >> r[i] >> c[i];
			if (i) {
				if (l[i]<l[bl]||(l[i]==l[bl]&&c[i]<c[bl]))
					bl=i;
				if (r[i]>r[br]||(r[i]==r[br]&&c[i]<c[br]))
					br=i;
				if (l[i]<=l[bb]&&r[i]>=r[bb])
					if (l[i]<l[bb]||r[i]>r[bb]||c[i]<c[bb])
						bb=i;
			}
			int ans=c[bl]+c[br];
			if (l[bb]==l[bl]&&r[bb]==r[br])
				ans=min(ans, c[bb]);
			cout << ans << "\n";
		}
	}
	return 0;
}
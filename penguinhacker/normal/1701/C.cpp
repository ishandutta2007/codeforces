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
		int n, m;
		cin >> n >> m;
		vector<int> cnt(n);
		for (int i=0; i<m; ++i) {
			int x;
			cin >> x, --x;
			++cnt[x];
		}
		int lb=1, rb=2*m;
		while(lb<rb) {
			int mid=(lb+rb)/2;
			ll bal=0;
			for (int i=0; i<n; ++i) {
				if (mid>=cnt[i])
					bal+=(mid-cnt[i])/2;
				else
					bal-=cnt[i]-mid;
			}
			if (bal>=0)
				rb=mid;
			else
				lb=mid+1;
		}
		cout << lb << "\n";
	}
	return 0;
}
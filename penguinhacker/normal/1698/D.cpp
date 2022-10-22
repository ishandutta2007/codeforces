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
		int lb=1, rb=n;
		while(lb<rb) {
			int mid=(lb+rb)/2;
			cout << "? " << lb << " " << mid << endl;
			int cnt=0;
			for (int i=lb; i<=mid; ++i) {
				int x;
				cin >> x;
				cnt+=lb<=x&&x<=mid;
			}
			if (cnt%2)
				rb=mid;
			else
				lb=mid+1;
		}
		cout << "! " << lb << endl;
	}
	return 0;
}
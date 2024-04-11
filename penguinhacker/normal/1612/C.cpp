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
		ll k, x;
		cin >> k >> x;
		ll lb=1, rb=2*k-1;
		while(lb<rb) {
			//cout << lb << " " << rb << endl;
			ll mid=(lb+rb)/2;
			ll y;
			if (mid<=k)
				y=mid*(mid+1)/2;
			else {
				y=k*k;
				ll m2=2*k-1-mid;
				y-=m2*(m2+1)/2;
			}
			if (y>=x)
				rb=mid;
			else
				lb=mid+1;
		}
		cout << lb << "\n";
	}
	return 0;
}
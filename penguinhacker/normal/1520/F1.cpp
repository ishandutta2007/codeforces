#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, t;

int qry(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	return (j-i+1)-x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	while(t--) {
		int k;
		cin >> k;
		int l=1, r=n;
		while(l<r) {
			int mid=(l+r)/2;
			if (qry(1, mid)>=k)
				r=mid;
			else
				l=mid+1;
		}
		cout << "! " << l << endl;
	}
	return 0;
}
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
		vector<int> a(n);
		for (int &i : a) cin >> i;
		int l=0, r=n-1;
		while(l<r) {
			int mid=(l+r)/2;
			int last=-1;
			int lb=mid, rb=n-1;
			bool b=1;
			while(lb<rb) {
				int nxt;
				if (a[lb]<=a[rb]) nxt=a[lb++];
				else nxt=a[rb--];
				if (nxt<last) {b=0; break;}
				last=nxt;
			}
			if (b) r=mid;
			else l=mid+1;
		}
		cout << l << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
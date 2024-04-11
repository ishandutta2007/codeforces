#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, t, a[200000], c[200000];
set<int> s;

void qry() {
	int p, x;
	cin >> p >> x, --p;
	while(1) {
		auto it=s.lower_bound(p);
		if (it==s.end())
			break;
		int k=*it;
		if (a[k]+x<c[k]) {
			a[k]+=x;
			break;
		}
		x-=c[k]-a[k];
		a[k]=c[k];
		s.erase(k);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> c[i];
		s.insert(i);
	}
	cin >> t;
	while(t--) {
		int q;
		cin >> q;
		if (q==1)
			qry();
		else {
			int p;
			cin >> p, --p;
			cout << a[p] << '\n';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
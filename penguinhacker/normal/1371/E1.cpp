#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p, a[2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);
	vector<int> ans;
	for (int x=1; x<=2000; ++x) {
		ll prod=1;
		bool pos=1;
		for (int i=n-1; ~i; --i) {
			int k=min(i+1, x+i-a[i]+1);
			if (k<=0) {
				pos=0; break;
			}
			prod=prod*k%p;
		}
		if (prod&&pos) ans.push_back(x);
	}
	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
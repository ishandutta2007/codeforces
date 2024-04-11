#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		sort(a, a+n);
		int cnt=0, ans=0;
		for (int i=0; i<n; ++i) {
			cnt++;
			if (cnt>=a[i]) {
				cnt=0;
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
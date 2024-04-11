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
		int n, x, y;
		cin >> n >> x >> y;
		int cur=60*x+y;
		int ans=69696969;
		while(n--) {
			int a, b;
			cin >> a >> b;
			int e=60*a+b;
			ans=min(ans, (e-cur+24*60)%(24*60));
		}
		cout << ans/60 << " " << ans%60 << "\n";
	}
	return 0;
}
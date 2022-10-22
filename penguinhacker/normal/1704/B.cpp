#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF=1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int ans=0, mn=INF, mx=-INF;
		while(n--) {
			int a;
			cin >> a;
			mn=min(mn, a);
			mx=max(mx, a);
			if (mx-mn>2*x) {
				++ans;
				mn=mx=a;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
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
		int n, q;
		cin >> n >> q;
		ll cnt[2]={}, sum[2]={};
		while(n--) {
			int a;
			cin >> a;
			++cnt[a%2];
			sum[a%2]+=a;
		}
		while(q--) {
			int t, x;
			cin >> t >> x;
			if (x%2==0) {
				sum[t]+=cnt[t]*x;
			} else {
				sum[t^1]+=sum[t]+cnt[t]*x;
				cnt[t^1]+=cnt[t];
				sum[t]=cnt[t]=0;
			}
			cout << sum[0]+sum[1] << "\n";
		}
	}
	return 0;
}
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
		int n, m;
		cin >> n >> m;
		auto Get=[&](int x) {
			vector<ar<ll, 2>> res;
			while(x--) {
				int a;
				cin >> a;
				int cnt=1;
				while(a%m==0) {
					a/=m;
					cnt*=m;
				}
				if (res.empty()||res.back()[0]!=a)
					res.push_back({a, cnt});
				else
					res.back()[1]+=cnt;
			}
			return res;
		};
		vector<ar<ll, 2>> v=Get(n);
		int k;
		cin >> k;
		cout << (v==Get(k)?"YES":"NO") << "\n";
	}
	return 0;
}
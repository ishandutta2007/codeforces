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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		for (int& i : a)
			cin >> i;
		bool ok=0;
		for (int rep=0; rep<2; ++rep) {
			ll cnt=0;
			bool can=0;
			for (int i : a)
				if (i>=2*n) {
					cnt+=i/n;
					can|=i/3>=n;
				}
			if (cnt>=m&&(can||(cnt-m)%2==0)) {
				ok=1;
				break;
			}
			swap(n, m);
		}
		cout << (ok?"Yes":"No") << "\n";
	}	
	return 0;
}
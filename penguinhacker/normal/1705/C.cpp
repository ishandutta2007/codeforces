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
		int n, m, q;
		string s;
		cin >> n >> m >> q >> s;
		vector<ar<ll, 2>> ops(m);
		vector<ll> lens(1, s.size());
		for (ar<ll, 2>& i : ops) {
			cin >> i[0] >> i[1], --i[0], --i[1];
			lens.push_back(lens.back()+i[1]-i[0]+1);
		}
		while(q--) {
			ll k;
			cin >> k, --k;
			for (int i=m-1; ~i; --i)
				if (k>=lens[i])
					k=(k-lens[i])+ops[i][0];
			assert(k<s.size());
			cout << s[k] << "\n";
		}
	}
	return 0;
}
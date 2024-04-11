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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		vector<int> pos, b;
		for (int i=0; i<n; ++i) {
			if (i>=x||i+x<n) {
				pos.push_back(i);
				b.push_back(a[i]);
			}
		}
		sort(b.begin(), b.end());
		for (int i=0; i<pos.size(); ++i)
			a[pos[i]]=b[i];
		bool ans=1;
		for (int i=1; i<n; ++i)
			ans&=a[i]>=a[i-1];
		cout << (ans?"YES":"NO") << "\n";
	}
	return 0;
}
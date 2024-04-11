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
		int n;
		cin >> n;
		vector<int> a(n);
		bool ok=1;
		for (int i=0; i<n; ++i) {
			cin >> a[i], --a[i];
			ok&=a[i]%2==i%2;
		}
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		vector<int> ans;
		auto Get=[&](int x) {
			return find(a.begin(), a.end(), x)-a.begin();
		};
		auto Op=[&](int x) {
			ans.push_back(x);
			reverse(a.begin(), a.begin()+x);
		};
		for (int i=0; i<n/2; ++i) {
			Op(Get(2*i)+1);
			Op(Get(2*i+1));
			Op(Get(2*i+1)+2);
			Op(3);
			Op(n-2*i);
		}
		Op(n);
		//for (int i : a)
		//	cout << i << " ";
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
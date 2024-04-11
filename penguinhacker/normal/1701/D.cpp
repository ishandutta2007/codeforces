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
		map<int, vector<ar<int, 2>>> upds;
		vector<int> ans(n);
		for (int i=1; i<=n; ++i) {
			int b;
			cin >> b;
			upds[i/(b+1)+1].push_back({b?i/b:69696969, i-1});
		}
		priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
		for (int i=1; i<=n; ++i) {
			for (auto x : upds[i])
				pq.push(x);
			assert(pq.size());
			ans[pq.top()[1]]=i;
			pq.pop();
		}
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
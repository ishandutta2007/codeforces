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
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> r;
		vector<int> ans(n);
		ans[0]=a, ans[n/2]=b;
		for (int i=1; i<=n; ++i)
			if (i!=a&&i!=b)
				r.push_back(i);
		for (int i=0; i<r.size()/2; ++i) {
			ans[n/2+i+1]=r[i];
			ans[i+1]=r[r.size()/2+i];
		}
		if (*min_element(ans.begin(), ans.begin()+n/2)!=a||*max_element(ans.begin()+n/2, ans.end())!=b) {
			cout << "-1\n";
			continue;
		}
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
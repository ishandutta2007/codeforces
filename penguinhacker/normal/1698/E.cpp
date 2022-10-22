#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, s;
		cin >> n >> s;
		vector<int> a(n), b(n), pos(n, -1);
		vector<bool> vis(n);
		for (int& i : a)
			cin >> i, --i;
		for (int i=0; i<n; ++i) {
			cin >> b[i], --b[i];
			if (b[i]>=0) {
				pos[b[i]]=i;
				vis[b[i]]=1;
			}
		}
		bool ok=1;
		for (int i=0; i<n; ++i)
			if (pos[i]!=-1)
				ok&=a[pos[i]]<=i+s;
		if (!ok) {
			cout << "0\n";
			continue;
		}
		vector<int> c, d;
		for (int i=0; i<n; ++i) {
			if (b[i]<0)
				c.push_back(a[i]);
			if (!vis[i])
				d.push_back(i);
		}
		sort(c.begin(), c.end());
		sort(d.begin(), d.end());
		assert(c.size()==d.size());
		ll ans=1;
		int ind=0;
		for (int i=0; i<d.size(); ++i) {
			while(ind<c.size()&&c[ind]<=d[i]+s)
				++ind;
			ans=ans*(ind-i)%M;
		}
		cout << ans << "\n";
	}
	return 0;
}
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
		for (int& i : a)
			cin >> i, --i;
		if (n==1) {
			cout << "-1\n";
			continue;
		}
		vector<bool> vis(n);
			for (int i=0; i+2<n; ++i) {
				for (int j=0; j<n; ++j)
					if (!vis[j]&&j!=a[i]) {
						vis[j]=1;
						cout << j+1 << " ";
						break;
					}
			}
			vector<int> nv;
			for (int i=0; i<n; ++i)
				if (!vis[i])
					nv.push_back(i);
			assert(nv.size()==2);
			if (nv[0]!=a[n-2]&&nv[1]!=a[n-1])
				cout << nv[0]+1 << " " << nv[1]+1 << "\n";
			else
				cout << nv[1]+1 << " " << nv[0]+1 << "\n";
	}
	return 0;
}
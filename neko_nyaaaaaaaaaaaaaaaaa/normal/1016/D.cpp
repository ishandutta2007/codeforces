#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	
	vector<vector<int>> ans(n, vector<int>(m));
	for (int k = 0; k <= 30; k++) {
		
		vector<int> ba, bb;
		
		for (int i = 0; i < n; i++) {if (a[i] & (1 << k)) ba.push_back(i);}
		for (int i = 0; i < m; i++) {if (b[i] & (1 << k)) bb.push_back(i);}
		
		if ((ba.size() + bb.size()) % 2) {cout << "NO"; return 0;}
		
		int kk = min(ba.size(), bb.size());
		
		for (int i = 0; i < kk; i++) {
			ans[ba[i]][bb[i]] |= (1 << k);
		}
		
		if (ba.size() > bb.size()) {
			for (int i = bb.size(); i < ba.size(); i++) {
				ans[ba[i]][0] |= (1 << k);
			}
		} else if (ba.size() < bb.size()) {
			for (int i = ba.size(); i < bb.size(); i++) {
				ans[0][bb[i]] |= (1 << k);
			}
		}
	}
	
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
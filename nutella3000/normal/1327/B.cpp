#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
 
 
 
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
 
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool used[n];
		for(int i = 0;i < n;i++) used[i] = false;
		bool bad = true;
		int id = -1;
		for(int i = 1;i <= n;i++) {
			int k;
			cin >> k;
			bool temp = false;
			for(int q = 0;q < k;q++) {
				int v;
				cin >> v;
				v--;
				if (used[v] || temp) continue;
				temp = true;
				used[v] = true;
			}
			if (!temp) id = i;
		}

		if (id != -1) {
			bad = false;
			cout << "IMPROVE" << '\n' << id << " ";
			for(int q = 0;q < n;q++) {
				if (!used[q]) {
					cout << q + 1 << '\n';
					break;
				}
			}
		}

		if (bad) cout << "OPTIMAL" << '\n';
	}    
}
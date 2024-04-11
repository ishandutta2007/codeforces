#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int32_t main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	if (n == 1) {cout << 0; return 0;}
	
	vector<vector<int>> dist(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	
	vector<int> e(n);
	for (int i = 0; i < n; i++) {cin >> e[i]; e[i]--;}
	reverse(e.begin(), e.end());
	
	vector<int> actual_ans;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
		      for (int j = 0; j < n; j++) {
		            dist[i][j] = min(dist[i][j], dist[i][e[k]] + dist[e[k]][j]);
		      }
		}
		
		int ans = 0;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				ans += dist[e[i]][e[j]];
			}
		}
		actual_ans.push_back(ans);
	}
	
	for (int i = n-1; i >= 0; i--) {
		cout << actual_ans[i] << " ";
	}
	
	return 0;
}
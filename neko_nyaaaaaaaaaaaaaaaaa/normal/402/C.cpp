#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int t; cin >> t;
	while (t--) {
	      int n, p; cin >> n >> p;
	      int k = 2*n + p;
	      set<pair<int, int>> ans;
	      for (int i = 1; i <= n; i++) {
	            int x = i, y = (i + 1 > n ? i - n + 1: i + 1);
	            if (x > y) swap(x, y);
	            ans.insert({x, y});
	            x = i, y = (i + 2 > n ? i - n + 2: i + 2);
	            if (x > y) swap(x, y);
	            ans.insert({x, y});
	            k -= 2; 
	      }
	      for (int i = 1; i <= n; i++) {
	            for (int j = i+1; j <= n; j++) {
	                  if (k == 0) break;
	                  if (ans.count({i, j}) == 0) {
	                        ans.insert({i, j}); k--;
	                  }
	            }
	      }
	      
	      for (auto u: ans) {
	            cout << u.first << " " << u.second << endl;
	      }
	}
	
	return 0;
}
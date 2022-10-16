#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; i++) {
	      for (int j = 1; j <= m; j++) {
	            cin >> a[i][j];
	      }
	}
	for (int j = 1; j <= m; j++) {
	      for (int i = 1; i <= n; i++) {
	            a[i][j] += a[i - 1][j];
	      }
	}
	int ans1 = 0;
	int ans2 = 0;
	for (int j = 1; j <= m; j++) {
	      int maxans = 0, ansdel = 0;
            for (int i = 1; i <= n; i++) {
                  if (a[i][j] - a[i - 1][j] == 0) continue;
                  int l = min(n - i + 1, k);
                  if (a[i + l - 1][j] - a[i - 1][j] > maxans) {
                        maxans = a[i + l - 1][j] - a[i - 1][j];
                        ansdel = a[i - 1][j];
                  }
            }
	      ans1 += maxans;
	      ans2 += ansdel;
	}
	cout << ans1 << " " << ans2;
	
      return 0;
}
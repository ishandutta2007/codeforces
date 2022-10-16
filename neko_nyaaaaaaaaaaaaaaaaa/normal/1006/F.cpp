#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> mp[25][25];

int n, m, half;
ll k, ans = 0, a[25][25];

void solveup(int x, int y, ll cur, int cnt) {
      cur ^= a[x][y];
      if (cnt == half) {
		mp[x][y][cur]++;
	} else {
	      if (x + 1 < n) solveup(x+1, y, cur, cnt+1);
	      if (y + 1 < m) solveup(x, y+1, cur, cnt+1);
	}
}

void solvedown(int x, int y, ll cur, int cnt) {
      if (cnt == n+m-2 - half) {
            ans += mp[x][y][cur ^ k];
      } else {
            if (x > 0) solvedown(x-1, y, cur ^ a[x][y], cnt+1);
	      if (y > 0) solvedown(x, y-1, cur ^ a[x][y], cnt+1);
      }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	half = (n + m - 2)/2;
	for (int i = 0; i < n; i++) {
	      for (int j = 0; j < m; j++) {
	            cin >> a[i][j];
	      }
	}
	
	solveup(0, 0, 0, 0);
	solvedown(n-1, m-1, 0, 0);
	
	cout << ans;
	
	return 0;
}
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 2e9 + 7;
const int max_n = 501;

int a[max_n][max_n];

int border(int n, int num) {
	if (n == 3) {
		a[2][0] = num++;
		a[2][1] = num++;
		a[1][1] = num++;
		a[1][2] = num++;
		a[0][1] = num++;
		a[0][0] = num++;
		a[1][0] = num++;
		a[0][2] = num++;
		a[2][2] = num++;
		return num;
	}

	if (n % 2 == 0) {
		for(int i = 0;i < n;i++) a[i][n - 1] = num++;
		for(int i = n - 2;i >= 0;i--) a[n - 1][i] = num++;
	}else{
		for(int i = 0;i < n;i++) a[n - 1][i] = num++;
		for(int i = n - 2;i >= 0;i--) a[i][n - 1] = num++;
	}
	
	return num;

}

void solve() {
	int n;
	cin >> n;
	if (n < 3) cout << -1;
	else{
		int m = n;
		int num = 1;
		while(m >= 3) {
			num = border(m, num);
			m--;
		}

		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) cout << a[i][j] << " ";
			cout << '\n';
		}
	}
}



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	solve();
}